#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKProjectile." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKProjectile." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKProjectile." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKProjectile : public Projectile
	{
	public:
			ADD_OBJECT( Vehicle, InstigatorBaseVehicle )
			ADD_VAR( ::FloatProperty, CustomGravityScaling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Buoyancy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TerminalVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LockWarningInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastLockWarningTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, InitialDir, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HomingTrackingStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseTrackingStrength, 0xFFFFFFFF )
			ADD_OBJECT( Actor, SeekTarget )
			ADD_VAR( ::FloatProperty, AccelRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CheckRadius, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNotBlockedByShield, 0x8 )
			ADD_VAR( ::BoolProperty, bCheckProjectileLight, 0x4 )
			ADD_VAR( ::BoolProperty, bShuttingDown, 0x2 )
			ADD_VAR( ::BoolProperty, bWideCheck, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
