#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKAnimBlendByHoverboarding." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKAnimBlendByHoverboarding." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKAnimBlendByHoverboarding." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimBlendByHoverboarding : public UDKAnimBlendBase
	{
	public:
			ADD_VAR( ::FloatProperty, FallTimeBeforeAnim, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoardLeanAmount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastActiveChildIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
