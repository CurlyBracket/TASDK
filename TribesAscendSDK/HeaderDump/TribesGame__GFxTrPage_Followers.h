#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrPage_Followers." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrPage_Followers." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrPage_Followers." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_Followers : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, MutalFriendLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SelectPromptLabel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RemovingIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevPlayerId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FocusedIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Criteria, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
