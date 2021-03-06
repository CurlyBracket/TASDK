#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AnimNodeSequence." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AnimNodeSequence." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AnimNodeSequence." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeSequence : public AnimNode
	{
	public:
			ADD_OBJECT( AnimSequence, AnimSeq )
			ADD_VAR( ::BoolProperty, bPlaying, 0x1 )
			ADD_VAR( ::FloatProperty, Rate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLooping, 0x2 )
			ADD_VAR( ::NameProperty, AnimSeqName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCauseActorAnimEnd, 0x4 )
			ADD_VAR( ::BoolProperty, bCauseActorAnimPlay, 0x8 )
			ADD_VAR( ::BoolProperty, bZeroRootRotation, 0x10 )
			ADD_VAR( ::BoolProperty, bZeroRootTranslation, 0x20 )
			ADD_VAR( ::BoolProperty, bDisableWarningWhenAnimNotFound, 0x40 )
			ADD_VAR( ::BoolProperty, bNoNotifies, 0x80 )
			ADD_VAR( ::BoolProperty, bForceRefposeWhenNotPlaying, 0x100 )
			ADD_VAR( ::BoolProperty, bIsIssuingNotifies, 0x200 )
			ADD_VAR( ::BoolProperty, m_bSuppressNotifies, 0x400 )
			ADD_VAR( ::BoolProperty, bForceAlwaysSlave, 0x800 )
			ADD_VAR( ::BoolProperty, bSynchronize, 0x1000 )
			ADD_VAR( ::BoolProperty, bReverseSync, 0x2000 )
			ADD_VAR( ::BoolProperty, bShowTimeLineSlider, 0x4000 )
			ADD_VAR( ::BoolProperty, bLoopCameraAnim, 0x8000 )
			ADD_VAR( ::BoolProperty, bRandomizeCameraAnimLoopStartTime, 0x10000 )
			ADD_VAR( ::BoolProperty, bEditorOnlyAddRefPoseToAdditiveAnimation, 0x20000 )
			ADD_VAR( ::FloatProperty, CurrentTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PreviousTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AnimLinkupIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NotifyWeightThreshold, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SynchGroupName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SynchPosOffset, 0xFFFFFFFF )
			ADD_OBJECT( CameraAnim, CameraAnim )
			ADD_OBJECT( CameraAnimInst, ActiveCameraAnimInstance )
			ADD_VAR( ::FloatProperty, CameraAnimScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraAnimPlayRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraAnimBlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraAnimBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RootBoneOption, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RootRotationOption, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
