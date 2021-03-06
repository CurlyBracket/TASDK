#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.UIDataProvider_SettingsArray." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.UIDataProvider_SettingsArray." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.UIDataProvider_SettingsArray." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_SettingsArray : public UIDataProvider
	{
	public:
			ADD_VAR( ::StrProperty, ColumnHeaderText, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SettingsName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SettingsId, 0xFFFFFFFF )
			ADD_OBJECT( Settings, Settings )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
