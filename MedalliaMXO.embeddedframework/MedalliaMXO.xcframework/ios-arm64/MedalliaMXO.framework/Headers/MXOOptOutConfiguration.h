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

/*!
A block type used for building an ``MXOOptOutConfiguration`` object.
*/
typedef void (^MXOOptOutConfigurationBuilderBlock)(MXOOptOutConfigurationBuilder *builder);


//=========================================
#pragma mark - MXOOptOutConfiguration
//=========================================

/**
The optout configuration object for the MXO SDK.
 
Used to include/exclude a user from specific levels of tracking, as defined by the ``MXOOptInOptions``. By default, the MXO SDK is opted in for all tracking.
 
## Properties
- `optOut`: The boolean identifying whether a user is opted out of tracking.
- `optInOptions`: Set of options that have opt in enabled.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
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
 }
 @Tab("Objective-C") {
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
 }
}
*/
@interface MXOOptOutConfiguration : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The boolean identifying whether a user is opted out of tracking.
 
If set to `true`, the user will be opted out of all tracking, regardless of the specified ``MXOOptInOptions``. No tracking of any kind will occur in this case.
  
If set to `false`, the user will be opted back in based on the specified ``MXOOptInOptions``. To opt back in, it is crucial to provide the necessary ``MXOOptInOptions``. Without specifying ``MXOOptInOptions``, the user will remain opted out.
*/
@property (nonatomic, assign, readonly) BOOL optOut;

/*!
Set of options that have opt in enabled.
 
Specifies the options to be opted back in when the `optOut` property is set to `false`.

If `optOut` is set to `true`, no tracking of any kind will occur, regardless of the specified ``MXOOptInOptions``.
  
If `optOut` is set to `false`, the user will be opted back in based on the specified ``MXOOptInOptions``. To opt back in, it is crucial to provide the necessary ``MXOOptInOptions``. Without specifying ``MXOOptInOptions``, the user will remain opted out.
*/
@property (nonatomic, assign, readonly) MXOOptInOptions optInOptions;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOOptOutConfiguration``.
 
## Returns
An instance of ``MXOOptOutConfigurationBuilder``.
*/
- (MXOOptOutConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOOptOutConfiguration`` using the provided `builder` block.
 
## Parameters
- `configBuilderBlock`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(nullable MXOOptOutConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOOptOutConfigurationBuilder
//=========================================

/**
The builder class designed to facilitate the creation of ``MXOOptOutConfiguration`` objects.
 
Provides a convenient way to configure and customize optout settings for user tracking.

## Properties
- `optOut`: The boolean identifying whether a user is opted out of tracking.
- `optInOptions`: Set of options that have opt in enabled.
*/
@interface MXOOptOutConfigurationBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/**
The boolean identifying whether a user is opted out of tracking.

If set to `true`, the user will be opted out of all tracking, regardless of the specified ``MXOOptInOptions``. No tracking of any kind will occur in this case.
 
If set to `false`, the user will be opted back in based on the specified ``MXOOptInOptions``. To opt back in, it is crucial to provide the necessary ``MXOOptInOptions``. Without specifying ``MXOOptInOptions``, the user will remain opted out.
*/
@property (nonatomic, assign) BOOL optOut;

/**
Set of options that have opt in enabled.
 
Specifies the options to be opted back in when the `optOut` property is set to `false`.

If `optOut` is set to `true`, no tracking of any kind will occur, regardless of the specified ``MXOOptInOptions``.
 
If `optOut` is set to `false`, the user will be opted back in based on the specified ``MXOOptInOptions``. To opt back in, it is crucial to provide the necessary ``MXOOptInOptions``. Without specifying ``MXOOptInOptions``, the user will remain opted out.
*/
@property (nonatomic, assign) MXOOptInOptions optInOptions;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOOptOutConfiguration`` object.
 
## Returns
An instance of ``MXOOptOutConfiguration``.
*/
- (MXOOptOutConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
