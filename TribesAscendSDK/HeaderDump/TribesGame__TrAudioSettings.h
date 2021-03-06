#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrAudioSettings." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrAudioSettings." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrAudioSettings." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAudioSettings : public GFxObject
	{
	public:
			ADD_VAR( ::IntProperty, m_nVolumeMaster, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nVolumeMusic, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nVolumeVoice, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nVolumeVGS, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nVolumeEffects, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, m_SettingsList )
			ADD_VAR( ::IntProperty, m_SettingsCount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
