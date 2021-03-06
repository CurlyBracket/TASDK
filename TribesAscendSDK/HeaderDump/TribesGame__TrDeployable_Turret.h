#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDeployable_Turret." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDeployable_Turret." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDeployable_Turret." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable_Turret : public TrDeployable
	{
	public:
			ADD_VAR( ::FloatProperty, m_fLastStallTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFireStallRestoreTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeToIgnoreInvulnerable, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeToAcquireTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTargetAcquiredTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_TargetAcquiredSoundCue )
			ADD_VAR( ::FloatProperty, m_fDeltaFireInterval, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bCanTargetVehicles, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEnabled, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
