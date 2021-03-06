#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.NxCylindricalForceField." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.NxCylindricalForceField." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.NxCylindricalForceField." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NxCylindricalForceField : public NxForceField
	{
	public:
			ADD_VAR( ::BoolProperty, UseSpecialRadialForce, 0x1 )
			ADD_VAR( ::FloatProperty, HeightOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EscapeVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LiftFalloffHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceTopRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LiftStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotationalStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialStrength, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
