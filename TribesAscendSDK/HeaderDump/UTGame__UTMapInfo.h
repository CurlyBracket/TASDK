#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTMapInfo." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTMapInfo." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTMapInfo." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTMapInfo : public UDKMapInfo
	{
	public:
			ADD_OBJECT( Texture, MapTexture )
			ADD_STRUCT( ::VectorProperty, MapCenter, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MapExtent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MapScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RecommendedPlayersMax, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RecommendedPlayersMin, 0xFFFFFFFF )
			ADD_OBJECT( UDKVehicle, KeyVehicles )
			ADD_OBJECT( MaterialInstanceConstant, GreenIconMaterialInstance )
			ADD_VAR( ::FloatProperty, ColorPercent, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CenterPos, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadarRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadarWidth, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ActualMapCenter, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UseableRadius, 0xFFFFFFFF )
			ADD_OBJECT( Material, MapMaterialReference )
			ADD_OBJECT( MaterialInstanceConstant, MapMaterialInstance )
			ADD_VAR( ::IntProperty, CurrentMapRotYaw, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MapRotY, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MapRotX, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, HUDIconsT )
			ADD_OBJECT( Material, HudIcons )
			ADD_OBJECT( Actor, WatchedActor )
			ADD_OBJECT( Actor, CurrentActor )
			ADD_VAR( ::BoolProperty, bMapUpToDate, 0x1 )
			ADD_VAR( ::FloatProperty, DefaultMapSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotatingMiniMapRange, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MapYaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MapTextureYaw, 0xFFFFFFFF )
			ADD_OBJECT( UTMapMusicInfo, MapMusicInfo )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
