
.. _stdlib_rtti:

================================
Runtime type information library
================================

.. include:: detail/rtti.rst

The RTTI module reflects runtime type information to daScript.
It also exposes daScript compiler infrastructure to daScript runtime.

All functions and symbols are in "rtti" module, use require to get access to it. ::

    require rtti


++++++++++++
Type aliases
++++++++++++

.. _alias-FileAccessPtr:

.. das:attribute:: FileAccessPtr = smart_ptr<rtti::FileAccess>

|typedef-rtti-FileAccessPtr|

.. _alias-ProgramFlags:

.. das:attribute:: ProgramFlags is a bitfield

+-----------------+---+-----+
+field            +bit+value+
+=================+===+=====+
+failToCompile    +0  +1    +
+-----------------+---+-----+
+unsafe           +1  +2    +
+-----------------+---+-----+
+isCompiling      +2  +4    +
+-----------------+---+-----+
+isSimulating     +3  +8    +
+-----------------+---+-----+
+isCompilingMacros+4  +16   +
+-----------------+---+-----+
+needMacroModule  +5  +32   +
+-----------------+---+-----+


|typedef-rtti-ProgramFlags|

.. _alias-RttiValue:

.. das:attribute:: RttiValueis a variant type

+-------+------+
+tBool  +bool  +
+-------+------+
+tInt   +int   +
+-------+------+
+tUInt  +uint  +
+-------+------+
+tInt64 +int64 +
+-------+------+
+tUInt64+uint64+
+-------+------+
+tFloat +float +
+-------+------+
+tDouble+double+
+-------+------+
+tString+string+
+-------+------+
+nothing+any   +
+-------+------+


|typedef-rtti-RttiValue|

.. _alias-context_category_flags:

.. das:attribute:: context_category_flags is a bitfield

+-----------------+---+-----+
+field            +bit+value+
+=================+===+=====+
+debug_context    +0  +1    +
+-----------------+---+-----+
+thread_clone     +1  +2    +
+-----------------+---+-----+
+job_clone        +2  +4    +
+-----------------+---+-----+
+opengl           +3  +8    +
+-----------------+---+-----+
+debugger_tick    +4  +16   +
+-----------------+---+-----+
+debugger_attached+5  +32   +
+-----------------+---+-----+


|typedef-rtti-context_category_flags|

+++++++++
Constants
+++++++++

.. _global-rtti-FUNCINFO_BUILTIN:

.. das:attribute:: FUNCINFO_BUILTIN = 0x2

|variable-rtti-FUNCINFO_BUILTIN|

.. _global-rtti-FUNCINFO_INIT:

.. das:attribute:: FUNCINFO_INIT = 0x1

|variable-rtti-FUNCINFO_INIT|

.. _global-rtti-FUNCINFO_PRIVATE:

.. das:attribute:: FUNCINFO_PRIVATE = 0x4

|variable-rtti-FUNCINFO_PRIVATE|

.. _global-rtti-FUNCINFO_SHUTDOWN:

.. das:attribute:: FUNCINFO_SHUTDOWN = 0x8

|variable-rtti-FUNCINFO_SHUTDOWN|

++++++++++++
Enumerations
++++++++++++

.. _enum-rtti-CompilationError:

.. das:attribute:: CompilationError

+-----------------------------------+-----+
+unspecified                        +0    +
+-----------------------------------+-----+
+mismatching_parentheses            +10001+
+-----------------------------------+-----+
+mismatching_curly_bracers          +10002+
+-----------------------------------+-----+
+string_constant_exceeds_file       +10003+
+-----------------------------------+-----+
+string_constant_exceeds_line       +10004+
+-----------------------------------+-----+
+unexpected_close_comment           +10005+
+-----------------------------------+-----+
+integer_constant_out_of_range      +10006+
+-----------------------------------+-----+
+comment_contains_eof               +10007+
+-----------------------------------+-----+
+invalid_escape_sequence            +10008+
+-----------------------------------+-----+
+invalid_line_directive             +10009+
+-----------------------------------+-----+
+syntax_error                       +20000+
+-----------------------------------+-----+
+malformed_ast                      +20001+
+-----------------------------------+-----+
+invalid_type                       +30101+
+-----------------------------------+-----+
+invalid_return_type                +30102+
+-----------------------------------+-----+
+invalid_argument_type              +30103+
+-----------------------------------+-----+
+invalid_structure_field_type       +30104+
+-----------------------------------+-----+
+invalid_array_type                 +30105+
+-----------------------------------+-----+
+invalid_table_type                 +30106+
+-----------------------------------+-----+
+invalid_argument_count             +30107+
+-----------------------------------+-----+
+invalid_variable_type              +30108+
+-----------------------------------+-----+
+invalid_new_type                   +30109+
+-----------------------------------+-----+
+invalid_index_type                 +30110+
+-----------------------------------+-----+
+invalid_annotation                 +30111+
+-----------------------------------+-----+
+invalid_swizzle_mask               +30112+
+-----------------------------------+-----+
+invalid_initialization_type        +30113+
+-----------------------------------+-----+
+invalid_with_type                  +30114+
+-----------------------------------+-----+
+invalid_override                   +30115+
+-----------------------------------+-----+
+invalid_name                       +30116+
+-----------------------------------+-----+
+invalid_array_dimension            +30117+
+-----------------------------------+-----+
+invalid_iteration_source           +30118+
+-----------------------------------+-----+
+invalid_loop                       +30119+
+-----------------------------------+-----+
+invalid_label                      +30120+
+-----------------------------------+-----+
+invalid_enumeration                +30121+
+-----------------------------------+-----+
+invalid_option                     +30122+
+-----------------------------------+-----+
+invalid_member_function            +30123+
+-----------------------------------+-----+
+function_already_declared          +30201+
+-----------------------------------+-----+
+argument_already_declared          +30202+
+-----------------------------------+-----+
+local_variable_already_declared    +30203+
+-----------------------------------+-----+
+global_variable_already_declared   +30204+
+-----------------------------------+-----+
+structure_field_already_declared   +30205+
+-----------------------------------+-----+
+structure_already_declared         +30206+
+-----------------------------------+-----+
+structure_already_has_initializer  +30207+
+-----------------------------------+-----+
+enumeration_already_declared       +30208+
+-----------------------------------+-----+
+enumeration_value_already_declared +30209+
+-----------------------------------+-----+
+type_alias_already_declared        +30210+
+-----------------------------------+-----+
+field_already_initialized          +30211+
+-----------------------------------+-----+
+type_not_found                     +30301+
+-----------------------------------+-----+
+structure_not_found                +30302+
+-----------------------------------+-----+
+operator_not_found                 +30303+
+-----------------------------------+-----+
+function_not_found                 +30304+
+-----------------------------------+-----+
+variable_not_found                 +30305+
+-----------------------------------+-----+
+handle_not_found                   +30306+
+-----------------------------------+-----+
+annotation_not_found               +30307+
+-----------------------------------+-----+
+enumeration_not_found              +30308+
+-----------------------------------+-----+
+enumeration_value_not_found        +30309+
+-----------------------------------+-----+
+type_alias_not_found               +30310+
+-----------------------------------+-----+
+bitfield_not_found                 +30311+
+-----------------------------------+-----+
+cant_initialize                    +30401+
+-----------------------------------+-----+
+cant_dereference                   +30501+
+-----------------------------------+-----+
+cant_index                         +30502+
+-----------------------------------+-----+
+cant_get_field                     +30503+
+-----------------------------------+-----+
+cant_write_to_const                +30504+
+-----------------------------------+-----+
+cant_move_to_const                 +30505+
+-----------------------------------+-----+
+cant_write_to_non_reference        +30506+
+-----------------------------------+-----+
+cant_copy                          +30507+
+-----------------------------------+-----+
+cant_move                          +30508+
+-----------------------------------+-----+
+cant_pass_temporary                +30509+
+-----------------------------------+-----+
+condition_must_be_bool             +30601+
+-----------------------------------+-----+
+condition_must_be_static           +30602+
+-----------------------------------+-----+
+cant_pipe                          +30701+
+-----------------------------------+-----+
+invalid_block                      +30801+
+-----------------------------------+-----+
+return_or_break_in_finally         +30802+
+-----------------------------------+-----+
+module_not_found                   +30901+
+-----------------------------------+-----+
+module_already_has_a_name          +30902+
+-----------------------------------+-----+
+cant_new_handle                    +31001+
+-----------------------------------+-----+
+bad_delete                         +31002+
+-----------------------------------+-----+
+cant_infer_generic                 +31100+
+-----------------------------------+-----+
+cant_infer_missing_initializer     +31101+
+-----------------------------------+-----+
+cant_infer_mismatching_restrictions+31102+
+-----------------------------------+-----+
+invalid_cast                       +31200+
+-----------------------------------+-----+
+incompatible_cast                  +31201+
+-----------------------------------+-----+
+unsafe                             +31300+
+-----------------------------------+-----+
+index_out_of_range                 +31400+
+-----------------------------------+-----+
+expecting_return_value             +32101+
+-----------------------------------+-----+
+not_expecting_return_value         +32102+
+-----------------------------------+-----+
+invalid_return_semantics           +32103+
+-----------------------------------+-----+
+invalid_yield                      +32104+
+-----------------------------------+-----+
+typeinfo_reference                 +39901+
+-----------------------------------+-----+
+typeinfo_auto                      +39902+
+-----------------------------------+-----+
+typeinfo_undefined                 +39903+
+-----------------------------------+-----+
+typeinfo_dim                       +39904+
+-----------------------------------+-----+
+typeinfo_macro_error               +39905+
+-----------------------------------+-----+
+static_assert_failed               +40100+
+-----------------------------------+-----+
+run_failed                         +40101+
+-----------------------------------+-----+
+annotation_failed                  +40102+
+-----------------------------------+-----+
+concept_failed                     +40103+
+-----------------------------------+-----+
+not_all_paths_return_value         +40200+
+-----------------------------------+-----+
+assert_with_side_effects           +40201+
+-----------------------------------+-----+
+only_fast_aot_no_cpp_name          +40202+
+-----------------------------------+-----+
+aot_side_effects                   +40203+
+-----------------------------------+-----+
+no_global_heap                     +40204+
+-----------------------------------+-----+
+no_global_variables                +40205+
+-----------------------------------+-----+
+unused_function_argument           +40206+
+-----------------------------------+-----+
+unsafe_function                    +40207+
+-----------------------------------+-----+
+too_many_infer_passes              +41000+
+-----------------------------------+-----+
+missing_node                       +50100+
+-----------------------------------+-----+


|enumeration-rtti-CompilationError|

.. _enum-rtti-ConstMatters:

.. das:attribute:: ConstMatters

+---+-+
+no +0+
+---+-+
+yes+1+
+---+-+


|enumeration-rtti-ConstMatters|

.. _enum-rtti-RefMatters:

.. das:attribute:: RefMatters

+---+-+
+no +0+
+---+-+
+yes+1+
+---+-+


|enumeration-rtti-RefMatters|

.. _enum-rtti-TemporaryMatters:

.. das:attribute:: TemporaryMatters

+---+-+
+no +0+
+---+-+
+yes+1+
+---+-+


|enumeration-rtti-TemporaryMatters|

.. _enum-rtti-Type:

.. das:attribute:: Type

+--------------+--+
+none          +0 +
+--------------+--+
+autoinfer     +1 +
+--------------+--+
+alias         +2 +
+--------------+--+
+fakeContext   +3 +
+--------------+--+
+fakeLineInfo  +4 +
+--------------+--+
+anyArgument   +5 +
+--------------+--+
+tVoid         +6 +
+--------------+--+
+tBool         +7 +
+--------------+--+
+tInt64        +12+
+--------------+--+
+tUInt64       +13+
+--------------+--+
+tInt          +14+
+--------------+--+
+tInt2         +15+
+--------------+--+
+tInt3         +16+
+--------------+--+
+tInt4         +17+
+--------------+--+
+tUInt         +18+
+--------------+--+
+tUInt2        +19+
+--------------+--+
+tUInt3        +20+
+--------------+--+
+tUInt4        +21+
+--------------+--+
+tFloat        +22+
+--------------+--+
+tFloat2       +23+
+--------------+--+
+tFloat3       +24+
+--------------+--+
+tFloat4       +25+
+--------------+--+
+tDouble       +26+
+--------------+--+
+tRange        +27+
+--------------+--+
+tURange       +28+
+--------------+--+
+tString       +29+
+--------------+--+
+tStructure    +30+
+--------------+--+
+tHandle       +31+
+--------------+--+
+tEnumeration  +32+
+--------------+--+
+tPointer      +36+
+--------------+--+
+tFunction     +37+
+--------------+--+
+tLambda       +38+
+--------------+--+
+tIterator     +39+
+--------------+--+
+tArray        +40+
+--------------+--+
+tTable        +41+
+--------------+--+
+tBlock        +42+
+--------------+--+
+tInt8         +8 +
+--------------+--+
+tUInt8        +9 +
+--------------+--+
+tInt16        +10+
+--------------+--+
+tUInt16       +11+
+--------------+--+
+tTuple        +43+
+--------------+--+
+tEnumeration8 +33+
+--------------+--+
+tEnumeration16+34+
+--------------+--+
+tVariant      +44+
+--------------+--+
+tBitfield     +35+
+--------------+--+


|enumeration-rtti-Type|

++++++++++++++++++
Handled structures
++++++++++++++++++

.. _handle-rtti-Annotation:

.. das:attribute:: Annotation

Annotation fields are

+-------+--------------------------------------------------------+
+_module+ :ref:`rtti::Module <handle-rtti-Module>` ?             +
+-------+--------------------------------------------------------+
+cppName+ :ref:`builtin::das_string <handle-builtin-das_string>` +
+-------+--------------------------------------------------------+
+name   + :ref:`builtin::das_string <handle-builtin-das_string>` +
+-------+--------------------------------------------------------+


Annotation properties are

+--------------------------+----+
+isFunctionAnnotation      +bool+
+--------------------------+----+
+isStructureTypeAnnotation +bool+
+--------------------------+----+
+isTypeAnnotation          +bool+
+--------------------------+----+
+isEnumerationAnnotation   +bool+
+--------------------------+----+
+isStructureAnnotation     +bool+
+--------------------------+----+
+isBasicStructureAnnotation+bool+
+--------------------------+----+


|structure_annotation-rtti-Annotation|

.. _handle-rtti-AnnotationArgument:

.. das:attribute:: AnnotationArgument

AnnotationArgument fields are

+---------+--------------------------------------------------------+
+fValue   +float                                                   +
+---------+--------------------------------------------------------+
+at       + :ref:`rtti::LineInfo <handle-rtti-LineInfo>`           +
+---------+--------------------------------------------------------+
+iValue   +int                                                     +
+---------+--------------------------------------------------------+
+name     + :ref:`builtin::das_string <handle-builtin-das_string>` +
+---------+--------------------------------------------------------+
+sValue   + :ref:`builtin::das_string <handle-builtin-das_string>` +
+---------+--------------------------------------------------------+
+bValue   +bool                                                    +
+---------+--------------------------------------------------------+
+basicType+ :ref:`rtti::Type <enum-rtti-Type>`                     +
+---------+--------------------------------------------------------+


|structure_annotation-rtti-AnnotationArgument|

.. _handle-rtti-AnnotationDeclaration:

.. das:attribute:: AnnotationDeclaration

AnnotationDeclaration fields are

+----------+--------------------------------------------------------------------------+
+annotation+smart_ptr< :ref:`rtti::Annotation <handle-rtti-Annotation>` >             +
+----------+--------------------------------------------------------------------------+
+arguments + :ref:`rtti::AnnotationArgumentList <handle-rtti-AnnotationArgumentList>` +
+----------+--------------------------------------------------------------------------+
+at        + :ref:`rtti::LineInfo <handle-rtti-LineInfo>`                             +
+----------+--------------------------------------------------------------------------+


|structure_annotation-rtti-AnnotationDeclaration|

.. _handle-rtti-BasicStructureAnnotation:

.. das:attribute:: BasicStructureAnnotation

BasicStructureAnnotation fields are

+-------+--------------------------------------------------------+
+cppName+ :ref:`builtin::das_string <handle-builtin-das_string>` +
+-------+--------------------------------------------------------+
+name   + :ref:`builtin::das_string <handle-builtin-das_string>` +
+-------+--------------------------------------------------------+


BasicStructureAnnotation properties are

+----------+---+
+fieldCount+int+
+----------+---+


|structure_annotation-rtti-BasicStructureAnnotation|

.. _handle-rtti-CodeOfPolicies:

.. das:attribute:: CodeOfPolicies

CodeOfPolicies fields are

+------------------------------+----+
+fail_on_no_aot                +bool+
+------------------------------+----+
+fail_on_lack_of_aot_export    +bool+
+------------------------------+----+
+debugger                      +bool+
+------------------------------+----+
+aot_order_side_effects        +bool+
+------------------------------+----+
+rtti                          +bool+
+------------------------------+----+
+ignore_shared_modules         +bool+
+------------------------------+----+
+allow_shared_lambda           +bool+
+------------------------------+----+
+multiple_contexts             +bool+
+------------------------------+----+
+heap_size_hint                +uint+
+------------------------------+----+
+persistent_heap               +bool+
+------------------------------+----+
+no_global_heap                +bool+
+------------------------------+----+
+intern_strings                +bool+
+------------------------------+----+
+no_optimizations              +bool+
+------------------------------+----+
+allow_block_variable_shadowing+bool+
+------------------------------+----+
+no_unused_function_arguments  +bool+
+------------------------------+----+
+stack                         +uint+
+------------------------------+----+
+no_unused_block_arguments     +bool+
+------------------------------+----+
+smart_pointer_by_value_unsafe +bool+
+------------------------------+----+
+no_global_variables           +bool+
+------------------------------+----+
+string_heap_size_hint         +uint+
+------------------------------+----+
+no_unsafe                     +bool+
+------------------------------+----+
+no_global_variables_at_all    +bool+
+------------------------------+----+
+only_fast_aot                 +bool+
+------------------------------+----+
+default_module_public         +bool+
+------------------------------+----+


|structure_annotation-rtti-CodeOfPolicies|

.. _handle-rtti-Context:

.. das:attribute:: Context

Context fields are

+----------------+--------------------------------------------------------------+
+breakOnException+bool                                                          +
+----------------+--------------------------------------------------------------+
+exception       +string const                                                  +
+----------------+--------------------------------------------------------------+
+category        + :ref:`context_category_flags <alias-context_category_flags>` +
+----------------+--------------------------------------------------------------+
+name            + :ref:`builtin::das_string <handle-builtin-das_string>`       +
+----------------+--------------------------------------------------------------+
+exceptionAt     + :ref:`rtti::LineInfo <handle-rtti-LineInfo>`                 +
+----------------+--------------------------------------------------------------+


Context properties are

+--------------+---+
+totalVariables+int+
+--------------+---+
+totalFunctions+int+
+--------------+---+


|structure_annotation-rtti-Context|

.. _handle-rtti-EnumInfo:

.. das:attribute:: EnumInfo

EnumInfo fields are

+-----------+------+
+count      +uint  +
+-----------+------+
+name       +string+
+-----------+------+
+module_name+string+
+-----------+------+
+hash       +uint  +
+-----------+------+


|structure_annotation-rtti-EnumInfo|

.. _handle-rtti-EnumValueInfo:

.. das:attribute:: EnumValueInfo

EnumValueInfo fields are

+-----+------+
+value+int64 +
+-----+------+
+name +string+
+-----+------+


|structure_annotation-rtti-EnumValueInfo|

.. _handle-rtti-Error:

.. das:attribute:: Error

Error fields are

+-----+------------------------------------------------------------+
+fixme+ :ref:`builtin::das_string <handle-builtin-das_string>`     +
+-----+------------------------------------------------------------+
+at   + :ref:`rtti::LineInfo <handle-rtti-LineInfo>`               +
+-----+------------------------------------------------------------+
+what + :ref:`builtin::das_string <handle-builtin-das_string>`     +
+-----+------------------------------------------------------------+
+extra+ :ref:`builtin::das_string <handle-builtin-das_string>`     +
+-----+------------------------------------------------------------+
+cerr + :ref:`rtti::CompilationError <enum-rtti-CompilationError>` +
+-----+------------------------------------------------------------+


|structure_annotation-rtti-Error|

.. _handle-rtti-FileAccess:

.. das:attribute:: FileAccess

|structure_annotation-rtti-FileAccess|

.. _handle-rtti-FileInfo:

.. das:attribute:: FileInfo

FileInfo fields are

+------------+--------------------------------------------------------+
+tabSize     +int                                                     +
+------------+--------------------------------------------------------+
+name        + :ref:`builtin::das_string <handle-builtin-das_string>` +
+------------+--------------------------------------------------------+
+sourceLength+uint                                                    +
+------------+--------------------------------------------------------+


FileInfo properties are

+------+------------+
+source+string const+
+------+------------+


|structure_annotation-rtti-FileInfo|

.. _handle-rtti-FuncInfo:

.. das:attribute:: FuncInfo

FuncInfo fields are

+----------+------------------------------------------------------------------+
+locals    + :ref:`rtti::LocalVariableInfo <handle-rtti-LocalVariableInfo>` ??+
+----------+------------------------------------------------------------------+
+stackSize +uint                                                              +
+----------+------------------------------------------------------------------+
+result    + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ?                   +
+----------+------------------------------------------------------------------+
+count     +uint                                                              +
+----------+------------------------------------------------------------------+
+cppName   +string                                                            +
+----------+------------------------------------------------------------------+
+name      +string                                                            +
+----------+------------------------------------------------------------------+
+hash      +uint                                                              +
+----------+------------------------------------------------------------------+
+localCount+uint                                                              +
+----------+------------------------------------------------------------------+
+flags     +uint                                                              +
+----------+------------------------------------------------------------------+


|structure_annotation-rtti-FuncInfo|

.. _handle-rtti-LineInfo:

.. das:attribute:: LineInfo

LineInfo fields are

+-----------+-----------------------------------------------+
+last_column+uint                                           +
+-----------+-----------------------------------------------+
+line       +uint                                           +
+-----------+-----------------------------------------------+
+last_line  +uint                                           +
+-----------+-----------------------------------------------+
+column     +uint                                           +
+-----------+-----------------------------------------------+
+fileInfo   + :ref:`rtti::FileInfo <handle-rtti-FileInfo>` ?+
+-----------+-----------------------------------------------+


|structure_annotation-rtti-LineInfo|

.. _handle-rtti-LocalVariableInfo:

.. das:attribute:: LocalVariableInfo

LocalVariableInfo fields are

+----------+--------------------------------------------------------------+
+visibility+ :ref:`rtti::LineInfo <handle-rtti-LineInfo>`                 +
+----------+--------------------------------------------------------------+
+argTypes  + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ??              +
+----------+--------------------------------------------------------------+
+size      +uint                                                          +
+----------+--------------------------------------------------------------+
+secondType+ :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ?               +
+----------+--------------------------------------------------------------+
+dimSize   +uint                                                          +
+----------+--------------------------------------------------------------+
+localFlags+ :ref:`LocalVariableInfoFlags <alias-LocalVariableInfoFlags>` +
+----------+--------------------------------------------------------------+
+enumType  + :ref:`rtti::EnumInfo <handle-rtti-EnumInfo>` ?               +
+----------+--------------------------------------------------------------+
+stackTop  +uint                                                          +
+----------+--------------------------------------------------------------+
+name      +string                                                        +
+----------+--------------------------------------------------------------+
+hash      +uint                                                          +
+----------+--------------------------------------------------------------+
+argNames  +string?                                                       +
+----------+--------------------------------------------------------------+
+argCount  +uint                                                          +
+----------+--------------------------------------------------------------+
+basicType + :ref:`rtti::Type <enum-rtti-Type>`                           +
+----------+--------------------------------------------------------------+
+firstType + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ?               +
+----------+--------------------------------------------------------------+
+structType+ :ref:`rtti::StructInfo <handle-rtti-StructInfo>` ?           +
+----------+--------------------------------------------------------------+


LocalVariableInfo properties are

+----------+-----------------------------------------------------------+
+isConst   +bool                                                       +
+----------+-----------------------------------------------------------+
+annotation+ :ref:`rtti::TypeAnnotation <handle-rtti-TypeAnnotation>` ?+
+----------+-----------------------------------------------------------+
+isRawPod  +bool                                                       +
+----------+-----------------------------------------------------------+
+isRef     +bool                                                       +
+----------+-----------------------------------------------------------+
+isImplicit+bool                                                       +
+----------+-----------------------------------------------------------+
+isRefType +bool                                                       +
+----------+-----------------------------------------------------------+
+isPod     +bool                                                       +
+----------+-----------------------------------------------------------+
+isTemp    +bool                                                       +
+----------+-----------------------------------------------------------+
+isRefValue+bool                                                       +
+----------+-----------------------------------------------------------+
+canCopy   +bool                                                       +
+----------+-----------------------------------------------------------+


|structure_annotation-rtti-LocalVariableInfo|

.. _handle-rtti-Module:

.. das:attribute:: Module

Module fields are

+----+--------------------------------------------------------+
+name+ :ref:`builtin::das_string <handle-builtin-das_string>` +
+----+--------------------------------------------------------+


|structure_annotation-rtti-Module|

.. _handle-rtti-ModuleGroup:

.. das:attribute:: ModuleGroup

|structure_annotation-rtti-ModuleGroup|

.. _handle-rtti-Program:

.. das:attribute:: Program

Program fields are

+------+------------------------------------------------------------------+
+flags + :ref:`ProgramFlags <alias-ProgramFlags>`                         +
+------+------------------------------------------------------------------+
+errors+ :ref:`builtin::dasvector`Error <handle-builtin-dasvector`Error>` +
+------+------------------------------------------------------------------+


|structure_annotation-rtti-Program|

.. _handle-rtti-SimFunction:

.. das:attribute:: SimFunction

SimFunction fields are

+---------------+-----------------------------------------------+
+stackSize      +uint                                           +
+---------------+-----------------------------------------------+
+mangledNameHash+uint                                           +
+---------------+-----------------------------------------------+
+mangledName    +string                                         +
+---------------+-----------------------------------------------+
+name           +string                                         +
+---------------+-----------------------------------------------+
+debugInfo      + :ref:`rtti::FuncInfo <handle-rtti-FuncInfo>` ?+
+---------------+-----------------------------------------------+


|structure_annotation-rtti-SimFunction|

.. _handle-rtti-StructInfo:

.. das:attribute:: StructInfo

StructInfo fields are

+-----------+------+
+size       +uint  +
+-----------+------+
+initializer+int   +
+-----------+------+
+count      +uint  +
+-----------+------+
+name       +string+
+-----------+------+
+module_name+string+
+-----------+------+
+hash       +uint  +
+-----------+------+
+flags      +uint  +
+-----------+------+


|structure_annotation-rtti-StructInfo|

.. _handle-rtti-TypeAnnotation:

.. das:attribute:: TypeAnnotation

TypeAnnotation fields are

+-------+--------------------------------------------------------+
+_module+ :ref:`rtti::Module <handle-rtti-Module>` ?             +
+-------+--------------------------------------------------------+
+cppName+ :ref:`builtin::das_string <handle-builtin-das_string>` +
+-------+--------------------------------------------------------+
+name   + :ref:`builtin::das_string <handle-builtin-das_string>` +
+-------+--------------------------------------------------------+


TypeAnnotation properties are

+-------------+----+
+is_any_vector+bool+
+-------------+----+


|structure_annotation-rtti-TypeAnnotation|

.. _handle-rtti-TypeInfo:

.. das:attribute:: TypeInfo

TypeInfo fields are

+----------+---------------------------------------------------+
+argTypes  + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ??   +
+----------+---------------------------------------------------+
+size      +uint                                               +
+----------+---------------------------------------------------+
+secondType+ :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ?    +
+----------+---------------------------------------------------+
+dimSize   +uint                                               +
+----------+---------------------------------------------------+
+enumType  + :ref:`rtti::EnumInfo <handle-rtti-EnumInfo>` ?    +
+----------+---------------------------------------------------+
+hash      +uint                                               +
+----------+---------------------------------------------------+
+argNames  +string?                                            +
+----------+---------------------------------------------------+
+argCount  +uint                                               +
+----------+---------------------------------------------------+
+basicType + :ref:`rtti::Type <enum-rtti-Type>`                +
+----------+---------------------------------------------------+
+firstType + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ?    +
+----------+---------------------------------------------------+
+structType+ :ref:`rtti::StructInfo <handle-rtti-StructInfo>` ?+
+----------+---------------------------------------------------+


TypeInfo properties are

+----------+-----------------------------------------------------------+
+isConst   +bool                                                       +
+----------+-----------------------------------------------------------+
+annotation+ :ref:`rtti::TypeAnnotation <handle-rtti-TypeAnnotation>` ?+
+----------+-----------------------------------------------------------+
+isRawPod  +bool                                                       +
+----------+-----------------------------------------------------------+
+isRef     +bool                                                       +
+----------+-----------------------------------------------------------+
+isImplicit+bool                                                       +
+----------+-----------------------------------------------------------+
+isRefType +bool                                                       +
+----------+-----------------------------------------------------------+
+isPod     +bool                                                       +
+----------+-----------------------------------------------------------+
+isTemp    +bool                                                       +
+----------+-----------------------------------------------------------+
+isRefValue+bool                                                       +
+----------+-----------------------------------------------------------+
+canCopy   +bool                                                       +
+----------+-----------------------------------------------------------+


|structure_annotation-rtti-TypeInfo|

.. _handle-rtti-VarInfo:

.. das:attribute:: VarInfo

VarInfo fields are

+--------------------+---------------------------------------------------------------------------------+
+argTypes            + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ??                                 +
+--------------------+---------------------------------------------------------------------------------+
+size                +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+value               +any                                                                              +
+--------------------+---------------------------------------------------------------------------------+
+secondType          + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ?                                  +
+--------------------+---------------------------------------------------------------------------------+
+dimSize             +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+enumType            + :ref:`rtti::EnumInfo <handle-rtti-EnumInfo>` ?                                  +
+--------------------+---------------------------------------------------------------------------------+
+name                +string                                                                           +
+--------------------+---------------------------------------------------------------------------------+
+hash                +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+argNames            +string?                                                                          +
+--------------------+---------------------------------------------------------------------------------+
+argCount            +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+sValue              +string                                                                           +
+--------------------+---------------------------------------------------------------------------------+
+offset              +uint                                                                             +
+--------------------+---------------------------------------------------------------------------------+
+basicType           + :ref:`rtti::Type <enum-rtti-Type>`                                              +
+--------------------+---------------------------------------------------------------------------------+
+firstType           + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ?                                  +
+--------------------+---------------------------------------------------------------------------------+
+annotation_arguments+ :ref:`rtti::AnnotationArguments <handle-rtti-AnnotationArguments>`  const? const+
+--------------------+---------------------------------------------------------------------------------+
+structType          + :ref:`rtti::StructInfo <handle-rtti-StructInfo>` ?                              +
+--------------------+---------------------------------------------------------------------------------+


VarInfo properties are

+----------+-----------------------------------------------------------+
+isConst   +bool                                                       +
+----------+-----------------------------------------------------------+
+annotation+ :ref:`rtti::TypeAnnotation <handle-rtti-TypeAnnotation>` ?+
+----------+-----------------------------------------------------------+
+isRawPod  +bool                                                       +
+----------+-----------------------------------------------------------+
+isRef     +bool                                                       +
+----------+-----------------------------------------------------------+
+isImplicit+bool                                                       +
+----------+-----------------------------------------------------------+
+isRefType +bool                                                       +
+----------+-----------------------------------------------------------+
+isPod     +bool                                                       +
+----------+-----------------------------------------------------------+
+isTemp    +bool                                                       +
+----------+-----------------------------------------------------------+
+isRefValue+bool                                                       +
+----------+-----------------------------------------------------------+
+canCopy   +bool                                                       +
+----------+-----------------------------------------------------------+


|structure_annotation-rtti-VarInfo|

+++++++++++++
Handled types
+++++++++++++

.. _handle-rtti-AnnotationArgumentList:

.. das:attribute:: AnnotationArgumentList

|any_annotation-rtti-AnnotationArgumentList|

.. _handle-rtti-AnnotationArguments:

.. das:attribute:: AnnotationArguments

|any_annotation-rtti-AnnotationArguments|

.. _handle-rtti-AnnotationList:

.. das:attribute:: AnnotationList

|any_annotation-rtti-AnnotationList|

+++++++++++++
Uncategorized
+++++++++++++

.. _function-_at_rtti_c__c_CodeOfPolicies:

.. das:function:: CodeOfPolicies()

CodeOfPolicies returns  :ref:`rtti::CodeOfPolicies <handle-rtti-CodeOfPolicies>` 

|function-rtti-CodeOfPolicies|

.. _function-_at_rtti_c__c_LineInfo:

.. das:function:: LineInfo()

LineInfo returns  :ref:`rtti::LineInfo <handle-rtti-LineInfo>` 

|function-rtti-LineInfo|

.. _function-_at_rtti_c__c_LineInfo_CI1_ls_H_ls_rtti_c__c_FileInfo_gr__gr_?_Ci_Ci_Ci_Ci:

.. das:function:: LineInfo(arg0: rtti::FileInfo? const implicit; arg1: int const; arg2: int const; arg3: int const; arg4: int const)

LineInfo returns  :ref:`rtti::LineInfo <handle-rtti-LineInfo>` 

+--------+--------------------------------------------------------------+
+argument+argument type                                                 +
+========+==============================================================+
+arg0    + :ref:`rtti::FileInfo <handle-rtti-FileInfo>` ? const implicit+
+--------+--------------------------------------------------------------+
+arg1    +int const                                                     +
+--------+--------------------------------------------------------------+
+arg2    +int const                                                     +
+--------+--------------------------------------------------------------+
+arg3    +int const                                                     +
+--------+--------------------------------------------------------------+
+arg4    +int const                                                     +
+--------+--------------------------------------------------------------+


|function-rtti-LineInfo|

.. _function-_at_rtti_c__c_add_annotation_argument_IH_ls_rtti_c__c_AnnotationArgumentList_gr__CIs:

.. das:function:: add_annotation_argument(annotation: AnnotationArgumentList implicit; name: string const implicit)

add_annotation_argument returns int

+----------+-----------------------------------------------------------------------------------+
+argument  +argument type                                                                      +
+==========+===================================================================================+
+annotation+ :ref:`rtti::AnnotationArgumentList <handle-rtti-AnnotationArgumentList>`  implicit+
+----------+-----------------------------------------------------------------------------------+
+name      +string const implicit                                                              +
+----------+-----------------------------------------------------------------------------------+


|function-rtti-add_annotation_argument|

.. _function-_at_rtti_c__c_basic_struct_for_each_field_CIH_ls_rtti_c__c_BasicStructureAnnotation_gr__CI0_ls_s;s;CH_ls_rtti_c__c_TypeInfo_gr_;u_gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: basic_struct_for_each_field(annotation: BasicStructureAnnotation const implicit; block: block<(string;string;rtti::TypeInfo const;uint):void> const implicit)

+----------+----------------------------------------------------------------------------------------------------+
+argument  +argument type                                                                                       +
+==========+====================================================================================================+
+annotation+ :ref:`rtti::BasicStructureAnnotation <handle-rtti-BasicStructureAnnotation>`  const implicit       +
+----------+----------------------------------------------------------------------------------------------------+
+block     +block<(string;string; :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const;uint):void> const implicit+
+----------+----------------------------------------------------------------------------------------------------+


|function-rtti-basic_struct_for_each_field|

.. _function-_at_rtti_c__c_builtin_is_same_type_CI1_ls_CH_ls_rtti_c__c_TypeInfo_gr__gr_?_CI1_ls_CH_ls_rtti_c__c_TypeInfo_gr__gr_?_CE_ls_rtti_c__c_RefMatters_gr__CE_ls_rtti_c__c_ConstMatters_gr__CE_ls_rtti_c__c_TemporaryMatters_gr__Cb:

.. das:function:: builtin_is_same_type(a: rtti::TypeInfo const? const implicit; b: rtti::TypeInfo const? const implicit; refMatters: RefMatters const; cosntMatters: ConstMatters const; tempMatters: TemporaryMatters const; topLevel: bool const)

builtin_is_same_type returns bool

+------------+--------------------------------------------------------------------+
+argument    +argument type                                                       +
+============+====================================================================+
+a           + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const? const implicit+
+------------+--------------------------------------------------------------------+
+b           + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const? const implicit+
+------------+--------------------------------------------------------------------+
+refMatters  + :ref:`rtti::RefMatters <enum-rtti-RefMatters>`  const              +
+------------+--------------------------------------------------------------------+
+cosntMatters+ :ref:`rtti::ConstMatters <enum-rtti-ConstMatters>`  const          +
+------------+--------------------------------------------------------------------+
+tempMatters + :ref:`rtti::TemporaryMatters <enum-rtti-TemporaryMatters>`  const  +
+------------+--------------------------------------------------------------------+
+topLevel    +bool const                                                          +
+------------+--------------------------------------------------------------------+


|function-rtti-builtin_is_same_type|

.. _function-_at_rtti_c__c_compile_CIs_CIs_CIH_ls_rtti_c__c_CodeOfPolicies_gr__CI0_ls_b;1_ls_H_ls_rtti_c__c_Program_gr__gr_?W;CH_ls__builtin__c__c_das_string_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: compile(module_name: string const implicit; codeText: string const implicit; codeOfPolicies: CodeOfPolicies const implicit; block: block<(bool;smart_ptr<rtti::Program>;das_string const):void> const implicit)

+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+argument      +argument type                                                                                                                                           +
+==============+========================================================================================================================================================+
+module_name   +string const implicit                                                                                                                                   +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+codeText      +string const implicit                                                                                                                                   +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+codeOfPolicies+ :ref:`rtti::CodeOfPolicies <handle-rtti-CodeOfPolicies>`  const implicit                                                                               +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+block         +block<(bool;smart_ptr< :ref:`rtti::Program <handle-rtti-Program>` >; :ref:`builtin::das_string <handle-builtin-das_string>`  const):void> const implicit+
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+


|function-rtti-compile|

.. _function-_at_rtti_c__c_compile_CIs_CIs_CIH_ls_rtti_c__c_CodeOfPolicies_gr__Cb_CI0_ls_b;1_ls_H_ls_rtti_c__c_Program_gr__gr_?W;CH_ls__builtin__c__c_das_string_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: compile(module_name: string const implicit; codeText: string const implicit; codeOfPolicies: CodeOfPolicies const implicit; exportAll: bool const; block: block<(bool;smart_ptr<rtti::Program>;das_string const):void> const implicit)

+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+argument      +argument type                                                                                                                                           +
+==============+========================================================================================================================================================+
+module_name   +string const implicit                                                                                                                                   +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+codeText      +string const implicit                                                                                                                                   +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+codeOfPolicies+ :ref:`rtti::CodeOfPolicies <handle-rtti-CodeOfPolicies>`  const implicit                                                                               +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+exportAll     +bool const                                                                                                                                              +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+block         +block<(bool;smart_ptr< :ref:`rtti::Program <handle-rtti-Program>` >; :ref:`builtin::das_string <handle-builtin-das_string>`  const):void> const implicit+
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+


|function-rtti-compile|

.. _function-_at_rtti_c__c_compile_file_CIs_CI1_ls_H_ls_rtti_c__c_FileAccess_gr__gr_?W_CI1_ls_H_ls_rtti_c__c_ModuleGroup_gr__gr_?_CIH_ls_rtti_c__c_CodeOfPolicies_gr__CI0_ls_b;1_ls_H_ls_rtti_c__c_Program_gr__gr_?W;CH_ls__builtin__c__c_das_string_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: compile_file(module_name: string const implicit; fileAccess: smart_ptr<rtti::FileAccess> const implicit; moduleGroup: rtti::ModuleGroup? const implicit; codeOfPolicies: CodeOfPolicies const implicit; block: block<(bool;smart_ptr<rtti::Program>;das_string const):void> const implicit)

+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+argument      +argument type                                                                                                                                           +
+==============+========================================================================================================================================================+
+module_name   +string const implicit                                                                                                                                   +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+fileAccess    +smart_ptr< :ref:`rtti::FileAccess <handle-rtti-FileAccess>` > const implicit                                                                            +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+moduleGroup   + :ref:`rtti::ModuleGroup <handle-rtti-ModuleGroup>` ? const implicit                                                                                    +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+codeOfPolicies+ :ref:`rtti::CodeOfPolicies <handle-rtti-CodeOfPolicies>`  const implicit                                                                               +
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
+block         +block<(bool;smart_ptr< :ref:`rtti::Program <handle-rtti-Program>` >; :ref:`builtin::das_string <handle-builtin-das_string>`  const):void> const implicit+
+--------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+


|function-rtti-compile_file|

.. _function-_at_rtti_c__c_describe_CI1_ls_CH_ls_rtti_c__c_TypeInfo_gr__gr_?_C_c:

.. das:function:: describe(type: rtti::TypeInfo const? const implicit)

describe returns string

+--------+--------------------------------------------------------------------+
+argument+argument type                                                       +
+========+====================================================================+
+type    + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const? const implicit+
+--------+--------------------------------------------------------------------+


|function-rtti-describe|

.. _function-_at_rtti_c__c_get_annotation_argument_value_CIH_ls_rtti_c__c_AnnotationArgument_gr__C_c:

.. das:function:: get_annotation_argument_value(info: AnnotationArgument const implicit)

get_annotation_argument_value returns  :ref:`RttiValue <alias-RttiValue>` 

+--------+---------------------------------------------------------------------------------+
+argument+argument type                                                                    +
+========+=================================================================================+
+info    + :ref:`rtti::AnnotationArgument <handle-rtti-AnnotationArgument>`  const implicit+
+--------+---------------------------------------------------------------------------------+


|function-rtti-get_annotation_argument_value|

.. _function-_at_rtti_c__c_get_das_type_name_CE_ls_rtti_c__c_Type_gr__C_c:

.. das:function:: get_das_type_name(type: Type const)

get_das_type_name returns string

+--------+------------------------------------------+
+argument+argument type                             +
+========+==========================================+
+type    + :ref:`rtti::Type <enum-rtti-Type>`  const+
+--------+------------------------------------------+


|function-rtti-get_das_type_name|

.. _function-_at_rtti_c__c_get_dim_CIH_ls_rtti_c__c_TypeInfo_gr__Ci_C_c:

.. das:function:: get_dim(typeinfo: TypeInfo const implicit; index: int const)

get_dim returns int

+--------+-------------------------------------------------------------+
+argument+argument type                                                +
+========+=============================================================+
+typeinfo+ :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const implicit+
+--------+-------------------------------------------------------------+
+index   +int const                                                    +
+--------+-------------------------------------------------------------+


|function-rtti-get_dim|

.. _function-_at_rtti_c__c_get_dim_CIH_ls_rtti_c__c_VarInfo_gr__Ci_C_c:

.. das:function:: get_dim(typeinfo: VarInfo const implicit; index: int const)

get_dim returns int

+--------+-----------------------------------------------------------+
+argument+argument type                                              +
+========+===========================================================+
+typeinfo+ :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const implicit+
+--------+-----------------------------------------------------------+
+index   +int const                                                  +
+--------+-----------------------------------------------------------+


|function-rtti-get_dim|

.. _function-_at_rtti_c__c_get_function_info_C*_Ci:

.. das:function:: get_function_info(context: any const; index: int const)

get_function_info returns  :ref:`rtti::FuncInfo <handle-rtti-FuncInfo>`  const&

+--------+-------------+
+argument+argument type+
+========+=============+
+context +any const    +
+--------+-------------+
+index   +int const    +
+--------+-------------+


|function-rtti-get_function_info|

.. _function-_at_rtti_c__c_get_line_info_C_l:

.. das:function:: get_line_info()

get_line_info returns  :ref:`rtti::LineInfo <handle-rtti-LineInfo>` 

|function-rtti-get_line_info|

.. _function-_at_rtti_c__c_get_mangled_name_CI1_ls_H_ls_rtti_c__c_TypeInfo_gr__gr_?_C_c:

.. das:function:: get_mangled_name(type: rtti::TypeInfo? const implicit)

get_mangled_name returns string

+--------+--------------------------------------------------------------+
+argument+argument type                                                 +
+========+==============================================================+
+type    + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>` ? const implicit+
+--------+--------------------------------------------------------------+


|function-rtti-get_mangled_name|

.. _function-_at_rtti_c__c_get_module_CIs:

.. das:function:: get_module(name: string const implicit)

get_module returns  :ref:`rtti::Module <handle-rtti-Module>` ?

+--------+---------------------+
+argument+argument type        +
+========+=====================+
+name    +string const implicit+
+--------+---------------------+


|function-rtti-get_module|

.. _function-_at_rtti_c__c_get_this_module_CI1_ls_H_ls_rtti_c__c_Program_gr__gr_?M:

.. das:function:: get_this_module(program: smart_ptr<rtti::Program> const implicit)

get_this_module returns  :ref:`rtti::Module <handle-rtti-Module>` ?

+--------+----------------------------------------------------------------------+
+argument+argument type                                                         +
+========+======================================================================+
+program +smart_ptr< :ref:`rtti::Program <handle-rtti-Program>` > const implicit+
+--------+----------------------------------------------------------------------+


|function-rtti-get_this_module|

.. _function-_at_rtti_c__c_get_total_functions_IH_ls_rtti_c__c_Context_gr_:

.. das:function:: get_total_functions(context: Context implicit)

get_total_functions returns int

+--------+-----------------------------------------------------+
+argument+argument type                                        +
+========+=====================================================+
+context + :ref:`rtti::Context <handle-rtti-Context>`  implicit+
+--------+-----------------------------------------------------+


|function-rtti-get_total_functions|

.. _function-_at_rtti_c__c_get_total_variables_IH_ls_rtti_c__c_Context_gr_:

.. das:function:: get_total_variables(context: Context implicit)

get_total_variables returns int

+--------+-----------------------------------------------------+
+argument+argument type                                        +
+========+=====================================================+
+context + :ref:`rtti::Context <handle-rtti-Context>`  implicit+
+--------+-----------------------------------------------------+


|function-rtti-get_total_variables|

.. _function-_at_rtti_c__c_get_variable_info_C*_Ci:

.. das:function:: get_variable_info(context: any const; index: int const)

get_variable_info returns  :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const&

+--------+-------------+
+argument+argument type+
+========+=============+
+context +any const    +
+--------+-------------+
+index   +int const    +
+--------+-------------+


|function-rtti-get_variable_info|

.. _function-_at_rtti_c__c_get_variable_value_CIH_ls_rtti_c__c_VarInfo_gr_:

.. das:function:: get_variable_value(varInfo: VarInfo const implicit)

get_variable_value returns  :ref:`RttiValue <alias-RttiValue>` 

+--------+-----------------------------------------------------------+
+argument+argument type                                              +
+========+===========================================================+
+varInfo + :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const implicit+
+--------+-----------------------------------------------------------+


|function-rtti-get_variable_value|

.. _function-_at_rtti_c__c_is_compatible_cast_CI1_ls_CH_ls_rtti_c__c_StructInfo_gr__gr_?_CI1_ls_CH_ls_rtti_c__c_StructInfo_gr__gr_?:

.. das:function:: is_compatible_cast(from: rtti::StructInfo const? const implicit; to: rtti::StructInfo const? const implicit)

is_compatible_cast returns bool

+--------+------------------------------------------------------------------------+
+argument+argument type                                                           +
+========+========================================================================+
+from    + :ref:`rtti::StructInfo <handle-rtti-StructInfo>`  const? const implicit+
+--------+------------------------------------------------------------------------+
+to      + :ref:`rtti::StructInfo <handle-rtti-StructInfo>`  const? const implicit+
+--------+------------------------------------------------------------------------+


|function-rtti-is_compatible_cast|

.. _function-_at_rtti_c__c_make_file_access_CIs_C_c:

.. das:function:: make_file_access(project: string const implicit)

make_file_access returns smart_ptr< :ref:`rtti::FileAccess <handle-rtti-FileAccess>` >

+--------+---------------------+
+argument+argument type        +
+========+=====================+
+project +string const implicit+
+--------+---------------------+


|function-rtti-make_file_access|

.. _function-_at_rtti_c__c_module_for_each_annotation_CI1_ls_H_ls_rtti_c__c_Module_gr__gr_?_CI0_ls_CH_ls_rtti_c__c_Annotation_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: module_for_each_annotation(module: rtti::Module? const implicit; block: block<(rtti::Annotation const):void> const implicit)

+--------+-------------------------------------------------------------------------------------+
+argument+argument type                                                                        +
+========+=====================================================================================+
+module  + :ref:`rtti::Module <handle-rtti-Module>` ? const implicit                           +
+--------+-------------------------------------------------------------------------------------+
+block   +block<( :ref:`rtti::Annotation <handle-rtti-Annotation>`  const):void> const implicit+
+--------+-------------------------------------------------------------------------------------+


|function-rtti-module_for_each_annotation|

.. _function-_at_rtti_c__c_module_for_each_enumeration_CI1_ls_H_ls_rtti_c__c_Module_gr__gr_?_CI0_ls_CH_ls_rtti_c__c_EnumInfo_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: module_for_each_enumeration(module: rtti::Module? const implicit; block: block<(rtti::EnumInfo const):void> const implicit)

+--------+---------------------------------------------------------------------------------+
+argument+argument type                                                                    +
+========+=================================================================================+
+module  + :ref:`rtti::Module <handle-rtti-Module>` ? const implicit                       +
+--------+---------------------------------------------------------------------------------+
+block   +block<( :ref:`rtti::EnumInfo <handle-rtti-EnumInfo>`  const):void> const implicit+
+--------+---------------------------------------------------------------------------------+


|function-rtti-module_for_each_enumeration|

.. _function-_at_rtti_c__c_module_for_each_function_CI1_ls_H_ls_rtti_c__c_Module_gr__gr_?_CI0_ls_CH_ls_rtti_c__c_FuncInfo_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: module_for_each_function(module: rtti::Module? const implicit; block: block<(rtti::FuncInfo const):void> const implicit)

+--------+---------------------------------------------------------------------------------+
+argument+argument type                                                                    +
+========+=================================================================================+
+module  + :ref:`rtti::Module <handle-rtti-Module>` ? const implicit                       +
+--------+---------------------------------------------------------------------------------+
+block   +block<( :ref:`rtti::FuncInfo <handle-rtti-FuncInfo>`  const):void> const implicit+
+--------+---------------------------------------------------------------------------------+


|function-rtti-module_for_each_function|

.. _function-_at_rtti_c__c_module_for_each_generic_CI1_ls_H_ls_rtti_c__c_Module_gr__gr_?_CI0_ls_CH_ls_rtti_c__c_FuncInfo_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: module_for_each_generic(module: rtti::Module? const implicit; block: block<(rtti::FuncInfo const):void> const implicit)

+--------+---------------------------------------------------------------------------------+
+argument+argument type                                                                    +
+========+=================================================================================+
+module  + :ref:`rtti::Module <handle-rtti-Module>` ? const implicit                       +
+--------+---------------------------------------------------------------------------------+
+block   +block<( :ref:`rtti::FuncInfo <handle-rtti-FuncInfo>`  const):void> const implicit+
+--------+---------------------------------------------------------------------------------+


|function-rtti-module_for_each_generic|

.. _function-_at_rtti_c__c_module_for_each_global_CI1_ls_H_ls_rtti_c__c_Module_gr__gr_?_CI0_ls_CH_ls_rtti_c__c_VarInfo_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: module_for_each_global(module: rtti::Module? const implicit; block: block<(rtti::VarInfo const):void> const implicit)

+--------+-------------------------------------------------------------------------------+
+argument+argument type                                                                  +
+========+===============================================================================+
+module  + :ref:`rtti::Module <handle-rtti-Module>` ? const implicit                     +
+--------+-------------------------------------------------------------------------------+
+block   +block<( :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const):void> const implicit+
+--------+-------------------------------------------------------------------------------+


|function-rtti-module_for_each_global|

.. _function-_at_rtti_c__c_module_for_each_structure_CI1_ls_H_ls_rtti_c__c_Module_gr__gr_?_CI0_ls_CH_ls_rtti_c__c_StructInfo_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: module_for_each_structure(module: rtti::Module? const implicit; block: block<(rtti::StructInfo const):void> const implicit)

+--------+-------------------------------------------------------------------------------------+
+argument+argument type                                                                        +
+========+=====================================================================================+
+module  + :ref:`rtti::Module <handle-rtti-Module>` ? const implicit                           +
+--------+-------------------------------------------------------------------------------------+
+block   +block<( :ref:`rtti::StructInfo <handle-rtti-StructInfo>`  const):void> const implicit+
+--------+-------------------------------------------------------------------------------------+


|function-rtti-module_for_each_structure|

.. _function-_at_rtti_c__c_program_for_each_module_CI1_ls_H_ls_rtti_c__c_Program_gr__gr_?M_CI0_ls_1_ls_H_ls_rtti_c__c_Module_gr__gr_?_gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: program_for_each_module(program: smart_ptr<rtti::Program> const implicit; block: block<(rtti::Module?):void> const implicit)

+--------+------------------------------------------------------------------------+
+argument+argument type                                                           +
+========+========================================================================+
+program +smart_ptr< :ref:`rtti::Program <handle-rtti-Program>` > const implicit  +
+--------+------------------------------------------------------------------------+
+block   +block<( :ref:`rtti::Module <handle-rtti-Module>` ?):void> const implicit+
+--------+------------------------------------------------------------------------+


|function-rtti-program_for_each_module|

.. _function-_at_rtti_c__c_program_for_each_registered_module_CI0_ls_1_ls_H_ls_rtti_c__c_Module_gr__gr_?_gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: program_for_each_registered_module(block: block<(rtti::Module?):void> const implicit)

+--------+------------------------------------------------------------------------+
+argument+argument type                                                           +
+========+========================================================================+
+block   +block<( :ref:`rtti::Module <handle-rtti-Module>` ?):void> const implicit+
+--------+------------------------------------------------------------------------+


|function-rtti-program_for_each_registered_module|

.. _function-_at_rtti_c__c_rtti_builtin_structure_for_each_annotation_CIH_ls_rtti_c__c_StructInfo_gr__CI_builtin__C_c_C_l:

.. das:function:: rtti_builtin_structure_for_each_annotation(struct: StructInfo const implicit; block: block<> const implicit)

+--------+-----------------------------------------------------------------+
+argument+argument type                                                    +
+========+=================================================================+
+struct  + :ref:`rtti::StructInfo <handle-rtti-StructInfo>`  const implicit+
+--------+-----------------------------------------------------------------+
+block   +block<> const implicit                                           +
+--------+-----------------------------------------------------------------+


|function-rtti-rtti_builtin_structure_for_each_annotation|

.. _function-_at_rtti_c__c_set_file_source_CI1_ls_H_ls_rtti_c__c_FileAccess_gr__gr_?M_CIs_CIs_C_c_C_l:

.. das:function:: set_file_source(access: smart_ptr<rtti::FileAccess> const implicit; fileName: string const implicit; text: string const implicit)

set_file_source returns bool

+--------+----------------------------------------------------------------------------+
+argument+argument type                                                               +
+========+============================================================================+
+access  +smart_ptr< :ref:`rtti::FileAccess <handle-rtti-FileAccess>` > const implicit+
+--------+----------------------------------------------------------------------------+
+fileName+string const implicit                                                       +
+--------+----------------------------------------------------------------------------+
+text    +string const implicit                                                       +
+--------+----------------------------------------------------------------------------+


|function-rtti-set_file_source|

.. _function-_at_rtti_c__c_simulate_C&I1_ls_H_ls_rtti_c__c_Program_gr__gr_?W_Cb_CI0_ls_b;_c;H_ls__builtin__c__c_das_string_gr__gr_1_ls_v_gr__builtin__C_c_C_l:

.. das:function:: simulate(program: smart_ptr<rtti::Program> const& implicit; useAot: bool const; block: block<(bool;__context;das_string):void> const implicit)

+--------+----------------------------------------------------------------------------------------------------+
+argument+argument type                                                                                       +
+========+====================================================================================================+
+program +smart_ptr< :ref:`rtti::Program <handle-rtti-Program>` > const& implicit                             +
+--------+----------------------------------------------------------------------------------------------------+
+useAot  +bool const                                                                                          +
+--------+----------------------------------------------------------------------------------------------------+
+block   +block<(bool;__context; :ref:`builtin::das_string <handle-builtin-das_string>` ):void> const implicit+
+--------+----------------------------------------------------------------------------------------------------+


|function-rtti-simulate|

.. _function-_at_rtti_c__c_sprint_data_CI?_CI1_ls_CH_ls_rtti_c__c_TypeInfo_gr__gr_?_Ct_C_c:

.. das:function:: sprint_data(data: void? const implicit; type: rtti::TypeInfo const? const implicit; flags: bitfield const)

sprint_data returns string

+--------+--------------------------------------------------------------------+
+argument+argument type                                                       +
+========+====================================================================+
+data    +void? const implicit                                                +
+--------+--------------------------------------------------------------------+
+type    + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const? const implicit+
+--------+--------------------------------------------------------------------+
+flags   +bitfield<> const                                                    +
+--------+--------------------------------------------------------------------+


|function-rtti-sprint_data|

.. _function-_at_rtti_c__c_sprint_data_Cf4_CI1_ls_CH_ls_rtti_c__c_TypeInfo_gr__gr_?_Ct_C_c:

.. das:function:: sprint_data(data: float4 const; type: rtti::TypeInfo const? const implicit; flags: bitfield const)

sprint_data returns string

+--------+--------------------------------------------------------------------+
+argument+argument type                                                       +
+========+====================================================================+
+data    +float4 const                                                        +
+--------+--------------------------------------------------------------------+
+type    + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const? const implicit+
+--------+--------------------------------------------------------------------+
+flags   +bitfield<> const                                                    +
+--------+--------------------------------------------------------------------+


|function-rtti-sprint_data|

.. _function-_at_rtti_c__c_this_context_C_c:

.. das:function:: this_context()

this_context returns  :ref:`rtti::Context <handle-rtti-Context>` &

|function-rtti-this_context|

.. _function-_at_rtti_c__c_using_CI0_ls__hh_XH_ls_rtti_c__c_CodeOfPolicies_gr__gr_1_ls_v_gr__builtin_:

.. das:function:: using(arg0: block<(rtti::CodeOfPolicies# explicit):void> const implicit)

+--------+----------------------------------------------------------------------------------------+
+argument+argument type                                                                           +
+========+========================================================================================+
+arg0    +block<( :ref:`rtti::CodeOfPolicies <handle-rtti-CodeOfPolicies>` #):void> const implicit+
+--------+----------------------------------------------------------------------------------------+


|function-rtti-using|

.. _function-_at_rtti_c__c_using_CI0_ls__hh_XH_ls_rtti_c__c_ModuleGroup_gr__gr_1_ls_v_gr__builtin_:

.. das:function:: using(arg0: block<(rtti::ModuleGroup# explicit):void> const implicit)

+--------+----------------------------------------------------------------------------------+
+argument+argument type                                                                     +
+========+==================================================================================+
+arg0    +block<( :ref:`rtti::ModuleGroup <handle-rtti-ModuleGroup>` #):void> const implicit+
+--------+----------------------------------------------------------------------------------+


|function-rtti-using|

.. _function-_at_rtti_c__c_RttiValue_nothing:

.. das:function:: RttiValue_nothing()

RttiValue_nothing returns auto

|function-rtti-RttiValue_nothing|

.. _function-_at_rtti_c__c_arg_names_CH_ls_rtti_c__c_TypeInfo_gr_:

.. das:function:: arg_names(info: TypeInfo const)

arg_names returns auto

+--------+----------------------------------------------------+
+argument+argument type                                       +
+========+====================================================+
+info    + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const+
+--------+----------------------------------------------------+


|function-rtti-arg_names|

.. _function-_at_rtti_c__c_arg_names_CH_ls_rtti_c__c_VarInfo_gr_:

.. das:function:: arg_names(info: VarInfo const)

arg_names returns auto

+--------+--------------------------------------------------+
+argument+argument type                                     +
+========+==================================================+
+info    + :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const+
+--------+--------------------------------------------------+


|function-rtti-arg_names|

.. _function-_at_rtti_c__c_arg_types_CH_ls_rtti_c__c_TypeInfo_gr_:

.. das:function:: arg_types(info: TypeInfo const)

arg_types returns auto

+--------+----------------------------------------------------+
+argument+argument type                                       +
+========+====================================================+
+info    + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const+
+--------+----------------------------------------------------+


|function-rtti-arg_types|

.. _function-_at_rtti_c__c_arg_types_CH_ls_rtti_c__c_VarInfo_gr_:

.. das:function:: arg_types(info: VarInfo const)

arg_types returns auto

+--------+--------------------------------------------------+
+argument+argument type                                     +
+========+==================================================+
+info    + :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const+
+--------+--------------------------------------------------+


|function-rtti-arg_types|

.. _function-_at_rtti_c__c_class_info_C.:

.. das:function:: class_info(cl: auto const)

class_info returns  :ref:`rtti::StructInfo <handle-rtti-StructInfo>`  const?

+--------+-------------+
+argument+argument type+
+========+=============+
+cl      +auto const   +
+--------+-------------+


|function-rtti-class_info|

.. _function-_at_rtti_c__c_context_for_each_function_CN_ls_info_gr_0_ls_CH_ls_rtti_c__c_FuncInfo_gr__gr_1_ls_v_gr__builtin_:

.. das:function:: context_for_each_function(blk: block<(info:rtti::FuncInfo const):void> const)

context_for_each_function returns auto

+--------+-----------------------------------------------------------------------------+
+argument+argument type                                                                +
+========+=============================================================================+
+blk     +block<(info: :ref:`rtti::FuncInfo <handle-rtti-FuncInfo>`  const):void> const+
+--------+-----------------------------------------------------------------------------+


|function-rtti-context_for_each_function|

.. _function-_at_rtti_c__c_context_for_each_variable_CN_ls_info_gr_0_ls_CH_ls_rtti_c__c_VarInfo_gr__gr_1_ls_v_gr__builtin_:

.. das:function:: context_for_each_variable(blk: block<(info:rtti::VarInfo const):void> const)

context_for_each_variable returns auto

+--------+---------------------------------------------------------------------------+
+argument+argument type                                                              +
+========+===========================================================================+
+blk     +block<(info: :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const):void> const+
+--------+---------------------------------------------------------------------------+


|function-rtti-context_for_each_variable|

.. _function-_at_rtti_c__c_each_dim_CH_ls_rtti_c__c_TypeInfo_gr_:

.. das:function:: each_dim(info: TypeInfo const)

each_dim returns auto

+--------+----------------------------------------------------+
+argument+argument type                                       +
+========+====================================================+
+info    + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const+
+--------+----------------------------------------------------+


|function-rtti-each_dim|

.. _function-_at_rtti_c__c_each_dim_CH_ls_rtti_c__c_VarInfo_gr_:

.. das:function:: each_dim(info: VarInfo const)

each_dim returns auto

+--------+--------------------------------------------------+
+argument+argument type                                     +
+========+==================================================+
+info    + :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const+
+--------+--------------------------------------------------+


|function-rtti-each_dim|

.. _function-_at_rtti_c__c_is_compatible_cast_CH_ls_rtti_c__c_StructInfo_gr__CH_ls_rtti_c__c_StructInfo_gr_:

.. das:function:: is_compatible_cast(a: StructInfo const; b: StructInfo const)

is_compatible_cast returns auto

+--------+--------------------------------------------------------+
+argument+argument type                                           +
+========+========================================================+
+a       + :ref:`rtti::StructInfo <handle-rtti-StructInfo>`  const+
+--------+--------------------------------------------------------+
+b       + :ref:`rtti::StructInfo <handle-rtti-StructInfo>`  const+
+--------+--------------------------------------------------------+


|function-rtti-is_compatible_cast|

.. _function-_at_rtti_c__c_is_same_type_CH_ls_rtti_c__c_TypeInfo_gr__CH_ls_rtti_c__c_TypeInfo_gr__CE_ls_rtti_c__c_RefMatters_gr__CE_ls_rtti_c__c_ConstMatters_gr__CE_ls_rtti_c__c_TemporaryMatters_gr__Cb:

.. das:function:: is_same_type(a: TypeInfo const; b: TypeInfo const; refMatters: RefMatters const; constMatters: ConstMatters const; temporaryMatters: TemporaryMatters const; topLevel: bool const)

is_same_type returns auto

+----------------+------------------------------------------------------------------+
+argument        +argument type                                                     +
+================+==================================================================+
+a               + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const              +
+----------------+------------------------------------------------------------------+
+b               + :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const              +
+----------------+------------------------------------------------------------------+
+refMatters      + :ref:`rtti::RefMatters <enum-rtti-RefMatters>`  const            +
+----------------+------------------------------------------------------------------+
+constMatters    + :ref:`rtti::ConstMatters <enum-rtti-ConstMatters>`  const        +
+----------------+------------------------------------------------------------------+
+temporaryMatters+ :ref:`rtti::TemporaryMatters <enum-rtti-TemporaryMatters>`  const+
+----------------+------------------------------------------------------------------+
+topLevel        +bool const                                                        +
+----------------+------------------------------------------------------------------+


|function-rtti-is_same_type|

.. _function-_at_rtti_c__c_structure_for_each_annotation_CH_ls_rtti_c__c_StructInfo_gr__CN_ls_ann;args_gr_0_ls_CH_ls_rtti_c__c_Annotation_gr_;CH_ls_rtti_c__c_AnnotationArguments_gr__gr_1_ls_v_gr__builtin_:

.. das:function:: structure_for_each_annotation(st: StructInfo const; subexpr: block<(ann:rtti::Annotation const;args:rtti::AnnotationArguments const):void> const)

structure_for_each_annotation returns auto

+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
+argument+argument type                                                                                                                                                   +
+========+================================================================================================================================================================+
+st      + :ref:`rtti::StructInfo <handle-rtti-StructInfo>`  const                                                                                                        +
+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
+subexpr +block<(ann: :ref:`rtti::Annotation <handle-rtti-Annotation>`  const;args: :ref:`rtti::AnnotationArguments <handle-rtti-AnnotationArguments>`  const):void> const+
+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------+


|function-rtti-structure_for_each_annotation|

.. _function-_at_rtti_c__c_type_info_CH_ls_rtti_c__c_LocalVariableInfo_gr_:

.. das:function:: type_info(vinfo: LocalVariableInfo const)

type_info returns  :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const?

+--------+----------------------------------------------------------------------+
+argument+argument type                                                         +
+========+======================================================================+
+vinfo   + :ref:`rtti::LocalVariableInfo <handle-rtti-LocalVariableInfo>`  const+
+--------+----------------------------------------------------------------------+


|function-rtti-type_info|

.. _function-_at_rtti_c__c_type_info_CH_ls_rtti_c__c_VarInfo_gr_:

.. das:function:: type_info(vinfo: VarInfo const)

type_info returns  :ref:`rtti::TypeInfo <handle-rtti-TypeInfo>`  const?

+--------+--------------------------------------------------+
+argument+argument type                                     +
+========+==================================================+
+vinfo   + :ref:`rtti::VarInfo <handle-rtti-VarInfo>`  const+
+--------+--------------------------------------------------+


|function-rtti-type_info|


