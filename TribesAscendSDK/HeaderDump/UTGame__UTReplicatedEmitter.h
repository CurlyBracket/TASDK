#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTReplicatedEmitter." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTReplicatedEmitter." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTReplicatedEmitter." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTReplicatedEmitter : public UTEmitter
	{
	public:
			ADD_VAR( ::FloatProperty, ServerLifeSpan, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, EmitterTemplate )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
