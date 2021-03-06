#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.MaterialExpression." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.MaterialExpression." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.MaterialExpression." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MaterialExpression : public Object
	{
	public:
			ADD_VAR( ::StrProperty, Desc, 0xFFFFFFFF )
			ADD_OBJECT( MaterialExpressionCompound, Compound )
			ADD_VAR( ::BoolProperty, bUsedByStaticParameterSet, 0x20 )
			ADD_VAR( ::BoolProperty, bHidePreviewWindow, 0x10 )
			ADD_VAR( ::BoolProperty, bShowOutputNameOnPin, 0x8 )
			ADD_VAR( ::BoolProperty, bIsParameterExpression, 0x4 )
			ADD_VAR( ::BoolProperty, bNeedToUpdatePreview, 0x2 )
			ADD_VAR( ::BoolProperty, bRealtimePreview, 0x1 )
			ADD_VAR( ::IntProperty, MaterialExpressionEditorY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaterialExpressionEditorX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EditorY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EditorX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
