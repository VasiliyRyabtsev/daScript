options no_unused_block_arguments = false
options no_unused_function_arguments = false
options indenting = 4

module json_boost shared public

require rtti
require ast
require strings
require daslib/json public
require daslib/ast_boost
require daslib/contracts
require daslib/templates
require daslib/strings_boost
require daslib/apply

def private is_json_ptr_value ( td : TypeDeclPtr )
    if td.baseType != Type tPointer
        return false
    if td.firstType == null
        return false
    if td.firstType.baseType != Type tStructure
        return false
    let st = td.firstType.structType
    if st.name!="JsonValue" && st._module.name!="json"
        return false
    return true


// replacing ExprIsVariant(value,name) => ExprIsVariant(value.value,name)
// replacing ExprAsVariant(value,name) => ExprAsVariant(value.value,name)
// if value is json::JsonValue?
[variant_macro(name="better_json")]
class private BetterJsonMacro : AstVariantMacro
    def override visitExprIsVariant(prog:ProgramPtr; mod:Module?; expr:smart_ptr<ExprIsVariant>) : ExpressionPtr
        if is_json_ptr_value(expr.value._type)
            var vdr <- new [[ExprField() at=expr.at, name:="value", value <- clone_expression(expr.value)]]
            var isv <- new [[ExprIsVariant() at=expr.at, name:=expr.name, value <- vdr ]]
            isv.genFlags = expr.genFlags
            return isv
        return [[ExpressionPtr]]
    def override visitExprAsVariant(prog:ProgramPtr; mod:Module?; expr:smart_ptr<ExprAsVariant>) : ExpressionPtr
        if is_json_ptr_value(expr.value._type)
            var vdr <- new [[ExprField() at=expr.at, name:="value", value <- clone_expression(expr.value)]]
            var isv <- new [[ExprAsVariant() at=expr.at, name:=expr.name, value <- vdr ]]
            isv.genFlags = expr.genFlags
            return isv
        return [[ExpressionPtr]]

[reader_macro(name="json")]
class private JsonReader : AstReaderMacro
    def override accept ( prog:ProgramPtr; mod:Module?; var expr:ExprReader?; ch:int; info:LineInfo ) : bool
        append(expr.sequence,ch)
        if ends_with(expr.sequence,"%%")
            let len = length(expr.sequence)
            resize(expr.sequence,len-2)
            return false
        else
            return true
    def override visit ( prog:ProgramPtr; mod:Module?; expr:smart_ptr<ExprReader> ) : ExpressionPtr
        let seqStr = string(expr.sequence)
        var error = ""
        var json = read_json(seqStr, error)
        if json == null
            macro_error(prog,expr.at,"json did not parse ({error})")
            return [[ExpressionPtr]]
        else
            var exx <- convert_to_expression(json,expr.at)
            return exx

[template(ent)]
def from_JV ( v:JsonValue?; ent : auto(EnumT); defV : EnumT = [[EnumT]] ) : EnumT
    if v==null || !(v.value is _string)
        return defV
    let name = v.value as _string
    var res : auto(EnumTT) = [[EnumT]]
    var ti = typeinfo(rtti_typeinfo type<EnumT>)
    for ef in *ti.enumType
        if name==ef.name
            unsafe
                res = reinterpret<EnumTT> (ef.value)
            return res
    panic("not a valid enumeration {name} in {typeinfo(typename type<EnumT>)}")
    return res

[generic,template(ent)]
def from_JV ( var v : JsonValue?; ent:string; defV:string="" )
    if v==null || !(v.value is _string)
        return defV
    else
        return v.value as _string

[generic,template(ent)]
def from_JV ( var v : JsonValue?; ent:bool; defV:bool=false )
    if v==null || !(v.value is _bool)
        return defV
    else
        return v.value as _bool

[generic,template(ent)]
def from_JV ( var v : JsonValue?; ent:float; defV:float=0. )
    if v==null || !(v.value is _number)
        return defV
    else
        return float(v.value as _number)

[generic,template(ent)]
def from_JV ( var v : JsonValue?; ent:int; defV:int=0 )
    if v==null || !(v.value is _number)
        return defV
    else
        return int(v.value as _number)

[generic,template(ent)]
def from_JV ( var v : JsonValue?; ent:bitfield; defV:bitfield=[[bitfield]] )
    if v==null || !(v.value is _number)
        return defV
    else
        return bitfield(v.value as _number)

[expect_any_vector_type(v)]
def JV ( v : auto(VecT) )
    static_if typeinfo(vector_dim type<VecT>)==2
        return JV({{"x" => JV(v.x); "y" => JV(v.y)}})
    static_elif typeinfo(vector_dim type<VecT>)==3
        return JV({{"x" => JV(v.x); "y" => JV(v.y); "z" => JV(v.z)}})
    static_elif typeinfo(vector_dim type<VecT>)==4
        return JV({{"x" => JV(v.x); "y" => JV(v.y); "z" => JV(v.z); "w" => JV(v.w)}})

[expect_any_vector_type(ent), template(ent)]
def from_JV ( var v : JsonValue?; ent: auto(VecT); defV:VecT=[[VecT]]  )
    if v==null
        return defV
    let VecV : auto(VecTT) = VecT()
    var vo & = unsafe(v.value as _object)
    static_if typeinfo(vector_dim VecV)==2
        return VecTT(
            vo["x"].value as _number,
            vo["y"].value as _number)
    static_elif typeinfo(vector_dim VecV)==3
        return VecTT(
            vo["x"].value as _number,
            vo["y"].value as _number,
            vo["z"].value as _number)
    static_elif typeinfo(vector_dim VecV)==4
        return VecTT(
            vo["x"].value as _number,
            vo["y"].value as _number,
            vo["z"].value as _number,
            vo["w"].value as _number)


def JV ( v : float )
    return new [[JsonValue value <- [[JsValue _number = double(v)]]]]

def JV ( v : int )
    return new [[JsonValue value <- [[JsValue _number = double(v)]]]]

def JV ( v : bitfield )
    return new [[JsonValue value <- [[JsValue _number = double(v)]]]]

def JV(val: int8): JsonValue?
    return new [[JsonValue value <- [[JsValue _number = double(val)]]]]

def JV(val: uint8): JsonValue?
    return new [[JsonValue value <- [[JsValue _number = double(val)]]]]

def JV(val: int16): JsonValue?
    return new [[JsonValue value <- [[JsValue _number = double(val)]]]]

def JV(val: uint16): JsonValue?
    return new [[JsonValue value <- [[JsValue _number = double(val)]]]]

def JV(val: uint): JsonValue?
    return new [[JsonValue value <- [[JsValue _number = double(val)]]]]

def JV(val: int64): JsonValue?
    return new [[JsonValue value <- [[JsValue _number = double(val)]]]]

def JV(val: uint64): JsonValue?
    return new [[JsonValue value <- [[JsValue _number = double(val)]]]]


def JV(value): JsonValue?
    static_if typeinfo(typename value) == "json::JsonValue?" || typeinfo(typename value) == "json::JsonValue? const"
        return value
    static_elif typeinfo(is_pointer value)
        return value == null ? null : _::JV(*value)
    static_elif typeinfo(is_enum value)
        return JV("{value}")
    static_elif typeinfo(is_string value)
        return _::JV(value)
    static_elif typeinfo(is_struct value)
        var map: table<string; JsonValue?>
        apply(value) <| $(name: string; field)
            static_if typeinfo(is_function field)
                pass // skip functions
            static_elif typeinfo(is_void_pointer field)
                pass // skip void?
            static_elif typeinfo(is_pointer field)
                if field != null
                    map[name] = _::JV(field)
            else
                map[name] = _::JV(field)
        return _::JV(map)
    static_elif typeinfo(is_table value)
        var map: table<string; JsonValue?>
        for k, v in keys(value), values(value)
            map[k] = _::JV(v)
        return _::JV(map)
    static_elif typeinfo(is_iterable value)
        var arr: array<JsonValue?>
        for x in value
            arr |> push <| _::JV(x)
        return _::JV(arr)
    else
        to_log(LOG_ERROR, "JSON: unsupported type {typeinfo(typename value)}\n")
        concept_assert(false, "unknown JV()")
        return null


def JV(val1; val2): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2)}])

def JV(val1; val2; val3): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2); _::JV(val3)}])

def JV(val1; val2; val3; val4): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2); _::JV(val3); _::JV(val4)}])

def JV(val1; val2; val3; val4; val5): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2); _::JV(val3); _::JV(val4); _::JV(val5)}])

def JV(val1; val2; val3; val4; val5; val6): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2); _::JV(val3); _::JV(val4); _::JV(val5); _::JV(val6)}])

def JV(val1; val2; val3; val4; val5; val6; val7): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2); _::JV(val3); _::JV(val4); _::JV(val5); _::JV(val6); _::JV(val7)}])

def JV(val1; val2; val3; val4; val5; val6; val7; val8): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2); _::JV(val3); _::JV(val4); _::JV(val5); _::JV(val6); _::JV(val7); _::JV(val8)}])

def JV(val1; val2; val3; val4; val5; val6; val7; val8; val9): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2); _::JV(val3); _::JV(val4); _::JV(val5); _::JV(val6); _::JV(val7); _::JV(val8); _::JV(val9)}])

def JV(val1; val2; val3; val4; val5; val6; val7; val8; val9; val10): JsonValue?
    return _::JV([{auto[] _::JV(val1); _::JV(val2); _::JV(val3); _::JV(val4); _::JV(val5); _::JV(val6); _::JV(val7); _::JV(val8); _::JV(val9); _::JV(val10)}])
