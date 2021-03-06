#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.Weapon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.Weapon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.Weapon." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Weapon : public Inventory
	{
	public:
			ADD_VAR( ::BoolProperty, bInstantHit, 0x10 )
			ADD_VAR( ::FloatProperty, WeaponRange, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentFireMode, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CachedMaxRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AIRating, 0xFFFFFFFF )
			ADD_OBJECT( AIController, AIController )
			ADD_VAR( ::FloatProperty, Priority, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultAnimSpeed, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bMeleeWeapon, 0x20 )
			ADD_VAR( ::BoolProperty, bWasDoNotActivate, 0x8 )
			ADD_VAR( ::BoolProperty, bWasOptionalSet, 0x4 )
			ADD_VAR( ::BoolProperty, bCanThrow, 0x2 )
			ADD_VAR( ::BoolProperty, bWeaponPutDown, 0x1 )
			ADD_STRUCT( ::VectorProperty, FireOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PutDownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EquipTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
