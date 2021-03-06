#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " WinDrv.XnaForceFeedbackManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty WinDrv.XnaForceFeedbackManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty WinDrv.XnaForceFeedbackManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class XnaForceFeedbackManager : public ForceFeedbackManager
	{
	public:
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
