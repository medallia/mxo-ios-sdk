//
//  MXOAutomaticInteractionTrackingConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOAutomaticInteractionTrackingConfigurationBuilder;

//=========================================
#pragma mark - typedef
//=========================================

/*!
A block type used for building an ``MXOAutomaticInteractionTrackingConfiguration`` object.
*/
typedef void (^MXOAutomaticInteractionTrackingConfigurationBuilderBlock)(MXOAutomaticInteractionTrackingConfigurationBuilder *builder);

//=========================================
#pragma mark - MXOAutomaticInteractionTrackingConfiguration
//=========================================

/*!
The configuration object for MXO SDK automatic Interaction tracking.
 
By default, automatic Interaction and outbound link tracking is enabled in the MXO SDK. However, you can limit this behavior.

## Properties
- `disableInteractionTracking`: The boolean indicating whether the Interaction tracking is disabled.
- `disableOutboundLinkTracking`: The boolean indicating whether the outbound link tracking is disabled.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.automaticInteractionTrackingConfiguration = MXOAutomaticInteractionTrackingConfiguration { builder in
     builder.disableInteractionTracking = true
     builder.disableOutboundLinkTracking = true
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 MedalliaMXO.automaticInteractionTrackingConfiguration = [MXOAutomaticInteractionTrackingConfiguration initWithBuilder:^(MXOAutomaticInteractionTrackingConfigurationBuilder * _Nonnull builder) {
     builder.disableInteractionTracking = YES;
     builder.disableOutboundLinkTracking = YES;
 }];
 ```
 }
}
*/
@interface MXOAutomaticInteractionTrackingConfiguration : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The boolean indicating whether the Interaction tracking is disabled.
 
Set to `true` to disable Interaction tracking.
*/
@property (nonatomic, assign, readonly) BOOL disableInteractionTracking;

/*!
The boolean indicating whether the outbound link tracking is disabled.
 
Set to `true` to disable updating outbound links.
*/
@property (nonatomic, assign, readonly) BOOL disableOutboundLinkTracking;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOAutomaticInteractionTrackingConfiguration``.
 
## Returns
 An instance of ``MXOAutomaticInteractionTrackingConfigurationBuilder``.
*/
- (MXOAutomaticInteractionTrackingConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOAutomaticInteractionTrackingConfiguration`` using the provided `builder` block.
  
## Parameters
- `configBuilderBlock`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(nullable MXOAutomaticInteractionTrackingConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOAutomaticInteractionTrackingConfigurationBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOAutomaticInteractionTrackingConfiguration`` objects.
 
Provides a convenient way to configure the automatic interaction tracking for the SDK.
 
## Properties
- `disableInteractionTracking`: The boolean indicating whether the Interaction tracking is disabled.
- `disableOutboundLinkTracking`: The boolean indicating whether the outbound link tracking is disabled.
*/
@interface MXOAutomaticInteractionTrackingConfigurationBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The boolean indicating whether the Interaction tracking is disabled.
 
Set to `true` to disable Interaction tracking.
*/
@property (nonatomic, assign) BOOL disableInteractionTracking;

/*!
The boolean indicating whether the outbound link tracking is disabled.
 
Set to `true` to disable updating outbound links.
*/
@property (nonatomic, assign) BOOL disableOutboundLinkTracking;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOAutomaticInteractionTrackingConfiguration`` object.
 
## Returns
An instance of ``MXOAutomaticInteractionTrackingConfiguration``.
*/
- (MXOAutomaticInteractionTrackingConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
