//
//  MXOAutomaticInteractionTrackingConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOAutomaticInteractionTrackingConfigurationBuilder;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - typedef
///////////////////////////////////////////////////////////////////////////////////////////

typedef void (^MXOAutomaticInteractionTrackingConfigurationBuilderBlock)(MXOAutomaticInteractionTrackingConfigurationBuilder *builder);

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOAutomaticInteractionTrackingConfiguration
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Configure the MXO SDK for automatic tracking.
 */
@interface MXOAutomaticInteractionTrackingConfiguration : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Define whether the MXO SDK will automatically track and send defined interactions.
 */
@property (nonatomic, assign, readonly) BOOL disableInteractionTracking;

/*!
   @brief Define whether the MXO SDK will automatically track and send out bound traffic.
 */
@property (nonatomic, assign, readonly) BOOL disableOutboundLinkTracking;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create a new builder from "this" instance for quick copying.
 */
- (MXOAutomaticInteractionTrackingConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Class Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create an instance using a builder.
   @param configBuilderBlock The block to create the instance.
 */
+ (instancetype)initWithBuilder:(nullable MXOAutomaticInteractionTrackingConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOAutomaticInteractionTrackingConfigurationBuilder
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief A builder to create an MXOAutomaticInteractionTrackingConfiguration.
 */
@interface MXOAutomaticInteractionTrackingConfigurationBuilder : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Define whether the MXO SDK will automatically track and send defined interactions.
 */
@property (nonatomic, assign) BOOL disableInteractionTracking;

/*!
   @brief Define whether the MXO SDK will automatically track and send out bound traffic.
 */
@property (nonatomic, assign) BOOL disableOutboundLinkTracking;


///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create a new MXOAutomaticInteractionTrackingConfiguration.
 */
- (MXOAutomaticInteractionTrackingConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
