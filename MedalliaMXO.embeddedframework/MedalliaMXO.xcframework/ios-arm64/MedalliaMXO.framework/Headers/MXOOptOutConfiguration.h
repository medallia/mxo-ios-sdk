//
//  MXOOptOutConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOOptOutConfigurationBuilder;

//=========================================
#pragma mark - typedef
//=========================================
typedef void (^MXOOptOutConfigurationBuilderBlock)(MXOOptOutConfigurationBuilder *builder);


//=========================================
#pragma mark - MXOOptOutConfiguration
//=========================================

/**
 Privacy Compliance Opt-Out Configuration. This configuration allows you to include/exclude a user from specific levels of tracking, as defined by the `MXOOptInOptions`.  By default, the MXO SDK is opted in for all settings.
 
 ## Example (Swift)
 ```swift
 // Opt out of all tracking, `optInOptions` are ignored when opted out.
 MedalliaMXO.optOutConfiguration = MXOOptOutConfiguration { builder in
    builder.optOut = true
 }

 // Opt back into all tracking, `optInOptions` are required to opt back into tracking options.
 MedalliaMXO.optOutConfiguration = MXOOptOutConfiguration { builder in
    builder.optOut = false
    builder.optInOptions = [.interactionTracking, .keychainTidStorage, .cityCountryDetection]
 }
 ```
 
 ## Example (Objective-C)
 ```objective-c
 // Opt out of all tracking, `optInOptions` are ignored when opted out.
 MedalliaMXO.optOutConfiguration = [MXOOptOutConfiguration initWithBuilder:^(MXOOptOutConfigurationBuilder * _Nonnull builder) {
    builder.optOut = YES;
 }];

 // Opt back into all tracking, `optInOptions` are required to opt back into tracking options.
 MedalliaMXO.optOutConfiguration = [MXOOptOutConfiguration initWithBuilder:^(MXOOptOutConfigurationBuilder * _Nonnull builder) {
    builder.optOut = NO;
    builder.optInOptions = (InteractionTracking | KeychainTidStorage | CityCountryDetection);
 }];
 ```
 */
@interface MXOOptOutConfiguration : NSObject

//=========================================
#pragma mark - Properties
//=========================================

@property (nonatomic, assign, readonly) BOOL optOut;

@property (nonatomic, assign, readonly) MXOOptInOptions optInOptions;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
   @brief Create a builder using "this" state.
 */
- (MXOOptOutConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
   @brief Create an instance using a builder.
 */
+ (instancetype)initWithBuilder:(nullable MXOOptOutConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOOptOutConfigurationBuilder
//=========================================


/**
 Builder class designed to facilitate the creation of `MXOOptOutConfiguration` objects. It provides a convenient way to configure and customize opt-out settings for user tracking.

 ## Example (Swift)
 ```swift
 // Opt out of all tracking, `optInOptions` are ignored when opted out.
 MedalliaMXO.optOutConfiguration = MXOOptOutConfiguration { builder in
    builder.optOut = true
 }

 // Opt back into all tracking, `optInOptions` are required to opt back into tracking options.
 MedalliaMXO.optOutConfiguration = MXOOptOutConfiguration { builder in
    builder.optOut = false
    builder.optInOptions = [.interactionTracking, .keychainTidStorage, .cityCountryDetection]
 }
 ```
 
 ## Example (Objective-C)
 ```objective-c
 // Opt out of all tracking, `optInOptions` are ignored when opted out.
 MedalliaMXO.optOutConfiguration = [MXOOptOutConfiguration initWithBuilder:^(MXOOptOutConfigurationBuilder * _Nonnull builder) {
    builder.optOut = YES;
 }];

 // Opt back into all tracking, `optInOptions` are required to opt back into tracking options.
 MedalliaMXO.optOutConfiguration = [MXOOptOutConfiguration initWithBuilder:^(MXOOptOutConfigurationBuilder * _Nonnull builder) {
    builder.optOut = NO;
    builder.optInOptions = (InteractionTracking | KeychainTidStorage | CityCountryDetection);
 }];
 ```
 */
@interface MXOOptOutConfigurationBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/**
 A boolean flag indicating the optOut setting.

 If set to `true`, the user will be opted out of all tracking, regardless of the specified `MXOOptInOptions`. No tracking of any kind will occur in this case.
 
 If set to `false`, the user will be opted back in based on the specified `MXOOptInOptions`. To opt back in, it is crucial to provide the necessary `MXOOptInOptions`. Without specifying `MXOOptInOptions`, the user will remain opted out.
 */
@property (nonatomic, assign) BOOL optOut;

/**
 Specifies the options to be opted back in when the `optOut` property is `false`.

 If `optOut` is set to `true`, no tracking of any kind will occur, regardless of the specified `MXOOptInOptions`.
 
 If `optOut` is set to `false`, the user will be opted back in based on the specified `MXOOptInOptions`. To opt back in, it is crucial to provide the necessary `MXOOptInOptions`. Without specifying `MXOOptInOptions`, the user will remain opted out.
 */
@property (nonatomic, assign) MXOOptInOptions optInOptions;


//=========================================
#pragma mark - Instance Methods
//=========================================
/*!
   @brief Create an MXOOptOutConfiguration.
 */
- (MXOOptOutConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
