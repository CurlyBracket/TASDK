#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ParticleModuleEventReceiverSpawn." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ParticleModuleEventReceiverSpawn." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ParticleModuleEventReceiverSpawn." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleEventReceiverSpawn : public ParticleModuleEventReceiverBase
	{
	public:
			ADD_VAR( ::BoolProperty, bInheritVelocity, 0x4 )
			ADD_VAR( ::BoolProperty, bUsePSysLocation, 0x2 )
			ADD_VAR( ::BoolProperty, bUseParticleTime, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
