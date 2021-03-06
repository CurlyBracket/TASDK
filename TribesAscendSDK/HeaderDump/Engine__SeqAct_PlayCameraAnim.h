#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_PlayCameraAnim." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_PlayCameraAnim." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_PlayCameraAnim." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_PlayCameraAnim : public SequenceAction
	{
	public:
			ADD_OBJECT( Actor, UserDefinedSpaceActor )
			ADD_VAR( ::ByteProperty, PlaySpace, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IntensityScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Rate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRandomStartTime, 0x2 )
			ADD_VAR( ::BoolProperty, bLoop, 0x1 )
			ADD_OBJECT( CameraAnim, CameraAnim )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
