#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKSkeletalMeshComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKSkeletalMeshComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKSkeletalMeshComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkeletalMeshComponent : public SkeletalMeshComponent
	{
	public:
			ADD_VAR( ::FloatProperty, ClearStreamingTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceLoadTextures, 0x1 )
			ADD_VAR( ::FloatProperty, FOV, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
