#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.SeqAct_ControlGameMovie." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.SeqAct_ControlGameMovie." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.SeqAct_ControlGameMovie." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_ControlGameMovie : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::IntProperty, EndOfRenderingMovieFrame, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StartOfRenderingMovieFrame, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MovieName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
