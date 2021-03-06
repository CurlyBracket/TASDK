#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrReticules." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrReticules." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrReticules." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrReticules : public GFxObject
	{
	public:
			ADD_VAR( ::IntProperty, m_nCurrentReticuleIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bVisible, 0x1 )
			ADD_VAR( ::FloatProperty, LastReticuleDepth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastAccuracy, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastCrossMode, 0xFFFFFFFF )
			ADD_OBJECT( Weapon, LastWeapon )
			ADD_OBJECT( GFxObject, ActiveReticule )
			ADD_OBJECT( GFxObject, ReticulesMC )
			ADD_OBJECT( WorldInfo, ThisWorld )
			ADD_OBJECT( GfxTrHud, HUD )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
