#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDevice_Spinfusor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDevice_Spinfusor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDevice_Spinfusor." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_Spinfusor : public TrDevice
	{
	public:
			ADD_OBJECT( SoundCue, m_SpinfusorIdleSound )
			ADD_OBJECT( SkelControlSingleBone, m_DiscVisibilityControl )
			ADD_OBJECT( TrSkelControl_SpinControl, m_DiscSpinControl )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
