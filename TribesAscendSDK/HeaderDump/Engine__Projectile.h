#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.Projectile." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.Projectile." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.Projectile." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Projectile : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, NetCullDistanceSquared, 0xFFFFFFFF )
			ADD_OBJECT( Actor, ImpactedActor )
			ADD_OBJECT( Controller, InstigatorController )
			ADD_OBJECT( SoundCue, ImpactSound )
			ADD_OBJECT( SoundCue, SpawnSound )
			ADD_VAR( ::FloatProperty, MomentumTransfer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Damage, 0xFFFFFFFF )
			ADD_OBJECT( Actor, ZeroCollider )
			ADD_VAR( ::BoolProperty, bRotationFollowsVelocity, 0x8 )
			ADD_VAR( ::BoolProperty, bBegunPlay, 0x4 )
			ADD_VAR( ::BoolProperty, bBlockedByInstigator, 0x2 )
			ADD_VAR( ::BoolProperty, bSwitchToZeroCollision, 0x1 )
			ADD_VAR( ::FloatProperty, MaxSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Speed, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
