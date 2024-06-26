//
//  MedalliaMXOAPI.h
//  Medallia
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define ONE_API_DEPRECATED(__VA_ARGS__) __attribute__((deprecated(__VA_ARGS__)));

NS_ASSUME_NONNULL_BEGIN

extern NSString *const MXOErrorDomain;

typedef NS_ERROR_ENUM(MXOErrorDomain, MXOErrorCode) {
    MXOErrorSDKError = 9000,
    MXOErrorAPIError,
    MXOErrorInvalidRequestError,
    MXOErrorInvalidParamError,
    MXOErrorInvalidSubscriberError
};

/*!
   @typedef MXOLogLevel
   @brief This is an enum which specifies the log level output which will be printed to console.
   @field MXOLogLevelNone This log level disables logging to console.
   @field MXOLogLevelVerbose  This log level prints everything to console.
   @field MXOLogLevelInfo This log level prints framework events which occur whilst running the app.
   @field MXOLogLevelWarn This log level prints framework warnings which occur whilst running the app.
   @field MXOLogLevelError This log level prints framework errors which occur whilst running the app.
   @field MXOLogLevelDebug This log level prints debug logs to console.
 */

typedef NS_OPTIONS(NSUInteger, MXOLogLevel) {
    MXOLogLevelNone NS_SWIFT_NAME(none)         = 1,
    MXOLogLevelVerbose NS_SWIFT_NAME(verbose)   = 1 << 1,
    MXOLogLevelInfo NS_SWIFT_NAME(info)         = 1 << 2,
    MXOLogLevelWarn NS_SWIFT_NAME(warn)         = 1 << 3,
    MXOLogLevelError NS_SWIFT_NAME(error)       = 1 << 4,
    MXOLogLevelDebug NS_SWIFT_NAME(debug)       = 1 << 5
};

/*!
   @typedef MXOLogComponent
   @brief This is an enum which specifies the log component which will be printed to console.
   @field MXOLogComponentNone This log component disables logging to console.
   @field MXOLogComponentAny This log component prints all logs to console.
   @field MXOLogComponentInteraction This log component prints framework events which occur whilst running the app.
   @field MXOLogComponentNetworking This log component prints everything relating to web services (requests, responses etc.) only.
 */
typedef NS_OPTIONS(NSUInteger, MXOLogComponent) {
    MXOLogComponentNone NS_SWIFT_NAME(none)                 = 1,
    MXOLogComponentAny NS_SWIFT_NAME(any)                   = 1 << 1,
    MXOLogComponentInteraction NS_SWIFT_NAME(interaction)   = 1 << 2,
    MXOLogComponentNetworking NS_SWIFT_NAME(networking)     = 1 << 3
};

/**
 Enum of options available for precise control over tracked customer information.  Use these options to specify your preferences for customer information tracking.
 */
typedef NS_OPTIONS(NSUInteger, MXOOptInOptions) {
    /**
     * Indicates whether Interaction Tracking is enabled.
     *
     * Use this option to track customer interactions.
     */
    InteractionTracking NS_SWIFT_NAME(interactionTracking)      = 1 << 0,
    /**
     * Indicates whether Keychain TID (Tracking Identifier) Storage is enabled.
     *
     * Use this option to securely store the customer's TID in the keychain.
     */
    KeychainTidStorage NS_SWIFT_NAME(keychainTidStorage)        = 1 << 1,
    /**
     * Indicates whether City and Country Detection is enabled.
     *
     * Use this option to track the customer's city and country using IPDetect, not the actual device location.
     */
    CityCountryDetection NS_SWIFT_NAME(cityCountryDetection)    = 1 << 2,
};

@protocol MXOAutomaticInteractionSubscription;

@class MXOConfiguration, MXOAutomaticInteractionSubscriber, MXOAutomaticInteractionTrackingConfiguration, MXOIdentityTransferConfiguration, MXOIdentityTransferConfiguration, MXOIdentityTransferUriMatcher, MXOInteractionRequest, MXOInteractionResponse, MXOResponseCodeRequest, MXOAutomaticInteractionAssignment, MXOAutomaticInteractionExclusion, MXOAutomaticInteractionInclusion, MXOInteraction, MXOLoggingConfiguration, MXOOptOutConfiguration;

@interface MedalliaMXO : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Version
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Returns the MXO SDK version.
   @return NSString
 */
+ (NSString *)getVersion NS_SWIFT_NAME(getVersion());

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Configuration
///////////////////////////////////////////////////////////////////////////////////////////

@property (class, nonatomic, nullable) MXOConfiguration *configuration;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Automatic Interaction Tracking
///////////////////////////////////////////////////////////////////////////////////////////

@property (class, nonatomic, nullable) MXOAutomaticInteractionTrackingConfiguration *automaticInteractionTrackingConfiguration;

+ (nullable id<MXOAutomaticInteractionSubscription>)subscribeToAutomaticInteraction:(MXOAutomaticInteractionSubscriber *)subscriber
                                                                              error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(subscribe(toAutomaticInteraction:));

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Identity Transfer
///////////////////////////////////////////////////////////////////////////////////////////

@property (class, nonatomic, nullable) MXOIdentityTransferConfiguration *identityTransferConfiguration;


/*!
   @brief Appends the MXO TID as parameter to a given URL.
   @param url A NSURL object.
   @return A NSURL object with the MXO TID.
 */
+ (nullable NSURL *)generateIdentityTransferUrl:(NSURL *)url
                                          error:(NSError *__autoreleasing _Nullable * _Nullable)error;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Identity
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Clears the App User's MXO TID.
 */
+ (void)clearTid NS_SWIFT_NAME(clearTid());

/*!
   @brief Returns the App User's MXO TID.
   @return NSString
 */
+ (nullable NSString *)getTid NS_SWIFT_NAME(getTid());

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Location
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Tell the MXO SDK to process a location update.
   @param location A CLLocation object.
 */
+ (BOOL)processLocation:(CLLocation *)location
                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(process(location:));

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Interaction API
///////////////////////////////////////////////////////////////////////////////////////////

+ (nullable MXOInteraction *)getAutomaticInteraction:(UIViewController *)viewController NS_SWIFT_NAME(getAutomaticInteraction(for:));

+ (BOOL)assignAutomaticInteraction:(MXOAutomaticInteractionAssignment *)assignInteraction
                    error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(assign(automaticInteraction:));

+ (BOOL)excludeAutomaticInteraction:(MXOAutomaticInteractionExclusion *)excludeInteration
                     error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(exclude(automaticInteraction:));

+ (BOOL)includeAutomaticInteraction:(MXOAutomaticInteractionInclusion *)includeInteration
                     error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(include(automaticInteraction:));

+ (BOOL)sendInteractionForOutboundLink:(NSURL *)link
                                 error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(sendInteraction(forOutboundLink:));

+ (BOOL)sendInteractionResponseCode:(MXOResponseCodeRequest *)request
                              error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(sendInteraction(responseCodeRequest:));

+ (BOOL)sendInteraction:(MXOInteractionRequest *)request
                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(sendInteraction(request:));

+ (BOOL)sendProperties:(MXOInteractionRequest *)request
                 error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(sendProperties(request:));

/*!
   @brief Handles a response received from MXO. All tracking and/or capture points will be parsed by the framework as usual. All optimization points, known by the framework, will be processed/displayed.
   @param response A MXOInteractionResponse instance.
 */
+ (BOOL)processResponse:(MXOInteractionResponse *)response
                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(process(response:));

/*!
   @brief Parses and sends URL parameters of a given URL to MXO
   @param url A NSURL object.
 */
+ (BOOL)processDeepLink:(NSURL *)url
                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(process(deepLink:));

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Logging
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Sets the framework's log level and component.
   @discussion Set specific logging configuration to see the framework outputs in the debug panel. 
 */
@property (class, nonatomic, nullable) MXOLoggingConfiguration *loggingConfiguration;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Opt
///////////////////////////////////////////////////////////////////////////////////////////

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
@property (class, nonatomic, nullable) MXOOptOutConfiguration *optOutConfiguration;

@end

NS_ASSUME_NONNULL_END
