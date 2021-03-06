#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SkelControlBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SkelControlBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SkelControlBase." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkelControlBase : public AnimObject
	{
	public:
			ADD_VAR( ::IntProperty, ControlPosY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ControlPosX, 0xFFFFFFFF )
			ADD_OBJECT( SkelControlBase, NextControl )
			ADD_VAR( ::IntProperty, IgnoreAtOrAboveLOD, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ControlTickTag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BoneScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AnimMetaDataUpdateTag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AnimMetadataWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendTimeToGo, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrengthTarget, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableEaseInOut, 0x80 )
			ADD_VAR( ::BoolProperty, bShouldTickInScript, 0x40 )
			ADD_VAR( ::BoolProperty, bIgnoreWhenNotRendered, 0x20 )
			ADD_VAR( ::BoolProperty, bPropagateSetActive, 0x10 )
			ADD_VAR( ::BoolProperty, bControlledByAnimMetada, 0x8 )
			ADD_VAR( ::BoolProperty, bInitializedCachedNodeList, 0x4 )
			ADD_VAR( ::BoolProperty, bSetStrengthFromAnimNode, 0x2 )
			ADD_VAR( ::BoolProperty, bPostPhysicsController, 0x1 )
			ADD_VAR( ::ByteProperty, BlendType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ControlStrength, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ControlName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
