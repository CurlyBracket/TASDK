#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_PlaySound." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_PlaySound." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_PlaySound." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_PlaySound : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::BoolProperty, bStopped, 0x2 )
			ADD_VAR( ::BoolProperty, bSuppressSubtitles, 0x1 )
			ADD_VAR( ::FloatProperty, PitchMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VolumeMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SoundDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExtraDelay, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, PlaySound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
