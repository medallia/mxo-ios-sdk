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

//=========================================
#pragma mark - typedef
//=========================================

/*!
The enum which specifies the MXO error codes.
 
## Options
- `MXOErrorSDKError`: Used to specify that an SDK error was encountered.
- `MXOErrorAPIError`: Used to specify that an API error was encountered.
- `MXOErrorInvalidRequestError`: Used to specify that an invalid request error was encountered.
- `MXOErrorInvalidParamError`: Used to specify that an invalid param error was encountered.
- `MXOErrorInvalidSubscriberError`: Used to specify that an invalid subscriber error was encountered.
*/
typedef NS_ERROR_ENUM(MXOErrorDomain, MXOErrorCode) {
    /**
    * Used to specify that an SDK error was encountered.
    */
    MXOErrorSDKError = 9000,
    /**
    * Used to specify that an API error was encountered.
    */
    MXOErrorAPIError,
    /**
    * Used to specify that an invalid request error was encountered.
    */
    MXOErrorInvalidRequestError,
    /**
    * Used to specify that an invalid param error was encountered.
    */
    MXOErrorInvalidParamError,
    /**
    * Used to specify that an invalid subscriber error was encountered.
    */
    MXOErrorInvalidSubscriberError
};

/*!
The enum which specifies the log level output which will be printed to console.
 
## Options
- `MXOLogLevelNone`: Nothing is logged. Used to opt out of logging.
- `MXOLogLevelVerbose`: Everything is logged.
- `MXOLogLevelInfo`: Info details are logged.
- `MXOLogLevelWarn`: Warning details are logged.
- `MXOLogLevelError`: Error details are logged.
- `MXOLogLevelDebug`: Debug details are logged.
*/
typedef NS_OPTIONS(NSUInteger, MXOLogLevel) {
    /**
    * Nothing is logged. Used to opt out of logging.
    */
    MXOLogLevelNone NS_SWIFT_NAME(none)         = 1,
    /**
    * Everything is logged.
    */
    MXOLogLevelVerbose NS_SWIFT_NAME(verbose)   = 1 << 1,
    /**
    * Info details are logged.
    */
    MXOLogLevelInfo NS_SWIFT_NAME(info)         = 1 << 2,
    /**
    * Warning details are logged.
    */
    MXOLogLevelWarn NS_SWIFT_NAME(warn)         = 1 << 3,
    /**
    * Error details are logged.
    */
    MXOLogLevelError NS_SWIFT_NAME(error)       = 1 << 4,
    /**
    * Debug details are logged.
    */
    MXOLogLevelDebug NS_SWIFT_NAME(debug)       = 1 << 5
};

/*!
The enum which specifies the log component which will be printed to console.
 
## Options
- `MXOLogComponentNone`: Nothing is logged. Used to opt out of logging.
- `MXOLogComponentAny`: Everything is logged.
- `MXOLogComponentInteraction`: Interaction tracking log messages.
- `MXOLogComponentNetworking`: Networking log messages.
*/
typedef NS_OPTIONS(NSUInteger, MXOLogComponent) {
    /**
    * Nothing is logged. Used to opt out of logging.
    */
    MXOLogComponentNone NS_SWIFT_NAME(none)                 = 1,
    /**
    * Everything is logged.
    */
    MXOLogComponentAny NS_SWIFT_NAME(any)                   = 1 << 1,
    /**
    * Interaction tracking log messages.
    */
    MXOLogComponentInteraction NS_SWIFT_NAME(interaction)   = 1 << 2,
    /**
    * Networking log messages.
    */
    MXOLogComponentNetworking NS_SWIFT_NAME(networking)     = 1 << 3
};

/**
The enum of options available for precise control over tracked customer information. 
 
Use these options to specify your preferences for customer information tracking.
 
## Options
- `InteractionTracking`: Indicates whether Interaction Tracking is enabled.
- `KeychainTidStorage`: Indicates whether Keychain TID (Tracking Identifier) Storage is enabled.
- `CityCountryDetection`: Indicates whether City and Country Detection is enabled.
*/
typedef NS_OPTIONS(NSUInteger, MXOOptInOptions) {
    /**
     * Indicates whether Interaction tracking is enabled.
     *
     * Use this option to track customer Interactions.
     */
    InteractionTracking NS_SWIFT_NAME(interactionTracking)      = 1 << 0,
    /**
     * Indicates whether keychain TID storage is enabled.
     *
     * Use this option to securely store the customer's TID in the keychain.
     */
    KeychainTidStorage NS_SWIFT_NAME(keychainTidStorage)        = 1 << 1,
    /**
     * Indicates whether city and country detection is enabled.
     *
     * Use this option to track the customer's city and country using `IPDetect`, not the actual device location.
     */
    CityCountryDetection NS_SWIFT_NAME(cityCountryDetection)    = 1 << 2,
};

@protocol MXOAutomaticInteractionSubscription;

@class MXOConfiguration, MXOAutomaticInteractionSubscriber, MXOAutomaticInteractionTrackingConfiguration, MXOIdentityTransferConfiguration, MXOIdentityTransferUriMatcher, MXOInteractionRequest, MXOInteractionResponse, MXOResponseCodeRequest, MXOAutomaticInteractionAssignment, MXOAutomaticInteractionExclusion, MXOAutomaticInteractionInclusion, MXOInteraction, MXOLoggingConfiguration, MXOOptOutConfiguration, MedalliaConfiguration;

/*!
The main object for the MXO SDK.
*/
@interface MedalliaMXO : NSObject

//=========================================
#pragma mark - Version
//=========================================

/*!
The version of the MXO SDK.
 
Use to get the current MXO SDK version.

## Returns
`NSString`
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let version = MedalliaMXO.getVersion()
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
  NSString *version = [MedalliaMXO getVersion];
 ```
 }
}
*/
+ (NSString *)getVersion NS_SWIFT_NAME(getVersion());

//=========================================
#pragma mark - Configuration
//=========================================

/*!
The configuration of the MXO SDK.
 
Use to set or get the MXO SDK configuration.
*/
@property (class, nonatomic, nullable) MXOConfiguration *configuration;

/*!
The Medallia configuration of the MXO SDK.
 
Use to set or get the Medallia SDK configuration.
*/
@property (class, nonatomic, nullable) MedalliaConfiguration *medalliaConfiguration;

//=========================================
#pragma mark - Automatic Interaction Tracking
//=========================================

/*!
The automatic Interaction tracking configuration of the MXO SDK.
 
Use to set or get the MXO SDK automatic Interaction tracking configuration.
*/
@property (class, nonatomic, nullable) MXOAutomaticInteractionTrackingConfiguration *automaticInteractionTrackingConfiguration;

/*!
Use to subscribe an MXO Interaction for automatic tracking.
 
## Parameters
- `subscriber`:  The subscriber for an Interaction.
- `error`: Used to handle errors.

## Returns
``MXOAutomaticInteractionSubscription``
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let interaction = MXOInteraction(withString: "/InteractionPath")
 MedalliaMXO.subscribe(toAutomaticInteraction: MXOAutomaticInteractionSubscriber { builder in
    builder.interaction = interaction
    builder.onResponse = { response in
        // do something with a response
    }
})
```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 MXOInteraction *interaction = [MXOInteraction initWithString:@"/InteractionPath" error:&error];
 [MedalliaMXO subscribeToAutomaticInteraction:[MXOAutomaticInteractionSubscriber initWithBuilder:^(MXOAutomaticInteractionSubscriberBuilder * _Nonnull builder) {
    builder.interaction = interaction;
    builder.onResponse = ^(MXOInteractionResponse *response) {
        // do something with a response
    };
}] error:&error];
```
 }
}
*/
+ (nullable id<MXOAutomaticInteractionSubscription>)subscribeToAutomaticInteraction:(MXOAutomaticInteractionSubscriber *)subscriber
                                                                              error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(subscribe(toAutomaticInteraction:));

//=========================================
#pragma mark - Identity Transfer
//=========================================

/*!
The identity transfer configuration of the MXO SDK.
 
Use to set or get the MXO SDK automatic Interaction tracking configuration.
*/
@property (class, nonatomic, nullable) MXOIdentityTransferConfiguration *identityTransferConfiguration;

/*!
Appends the MXO TID as parameter to a given `URL`.

## Parameters
- `url`:  A `NSURL` object.
- `error`: Used to handle errors.
 
## Returns
`NSURL` object with the MXO TID appended.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 if let url = URL(string: "yourUrl") {
     let identityUrl = try? MedalliaMXO.generateIdentityTransferUrl(url)
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 [MedalliaMXO generateIdentityTransferUrl:[NSURL URLWithString:@"yourUrl"] error:nil];
 ```
 }
}
*/
+ (nullable NSURL *)generateIdentityTransferUrl:(NSURL *)url
                                          error:(NSError *__autoreleasing _Nullable * _Nullable)error;

//=========================================
#pragma mark - Identity
//=========================================

/*!
Use to clear the current user's TID from the MXO SDK.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.clearTid()
  ```
 }
 @Tab("Objective-C") {
 ```objective-c
 [MedalliaMXO clearTid];
 ```
 }
}
*/
+ (void)clearTid NS_SWIFT_NAME(clearTid());

/*!
Use to get the current user's TID from the MXO SDK.

## Returns
`NSString`
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let tid = MedalliaMXO.getTid()
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSString *tid = [MedalliaMXO getTid];
 ```
 }
}
*/
+ (nullable NSString *)getTid NS_SWIFT_NAME(getTid());

//=========================================
#pragma mark - Location
//=========================================

/*!
Use to inform the MXO SDK about location details.
 
## Parameters
- `location`: The device location to send to MXO.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.process(location: clLocation)
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 [MedalliaMXO processLocation:location error:&error];
 ```
 }
}
*/
+ (BOOL)processLocation:(CLLocation *)location
                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(process(location:));

//=========================================
#pragma mark - Interaction API
//=========================================

/*!
Use to retrieve an MXO automatic Interaction.
 
The MXO SDK considers `UIViewController`s as Interactions. When configured correctly the SDK automatically sends an Interaction request to MXO and process the response. If desired, you can be notified of these automatic Interactions.
 
## Parameters
- `viewController`: The `UIViewController` to get an automatic Interaction for.
 
## Returns
``MXOInteraction``
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let mxoInteraction = MedalliaMXO.getAutomaticInteraction
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 MXOInteraction *mxoInteraction = [MedalliaMXO getAutomaticInteraction:self];
 ```
 }
}
*/
+ (nullable MXOInteraction *)getAutomaticInteraction:(UIViewController *)viewController NS_SWIFT_NAME(getAutomaticInteraction(for:));

/*!
Use to assign an automatic Interaction to a `UIViewController` to be used instead of using the automatic path.
 
## Parameters
- `assignInteraction`: The Interaction to assign to automatic tracking.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let interaction = MXOInteraction(withString: "/InteractionPath")
 MedalliaMXO.assign(automaticInteraction: MXOAutomaticInteractionAssignment { builder in
     builder.interaction = interaction
     builder.viewController = self
 })
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 __weak typeof(self) weakSelf = self;
 MXOInteraction *interaction = [MXOInteraction initWithString:@"/InteractionPath" error:&error];
 [MedalliaMXO assignAutomaticInteraction:[MXOAutomaticInteractionAssignment initWithBuilder:^(MXOAutomaticInteractionAssignmentBuilder * _Nonnull builder) {
     builder.interaction = interaction;
     builder.viewController = weakSelf;
 }] error:&error];
 ```
 }
}
*/
+ (BOOL)assignAutomaticInteraction:(MXOAutomaticInteractionAssignment *)assignInteraction
                    error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(assign(automaticInteraction:));

/*!
Use to exclude a `UIViewController` from automatically being tracked as an Interaction.
 
## Parameters
- `excudeInteraction`: The Interaction to exclude from tracking.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
MedalliaMXO.exclude(automaticInteraction: MXOAutomaticInteractionExclusion { builder in
    builder.viewController = self
})
```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 __weak typeof(self) weakSelf = self;
 [MedalliaMXO excludeAutomaticInteraction:[MXOAutomaticInteractionExclusion initWithBuilder:^(MXOAutomaticInteractionExclusionBuilder * _Nonnull builder) {
    builder.viewController = weakSelf;
}] error:&error];
 ```
 }
}
*/
+ (BOOL)excludeAutomaticInteraction:(MXOAutomaticInteractionExclusion *)excludeInteration
                     error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(exclude(automaticInteraction:));

/*!
Use to include a `UIViewController` for automatically being tracked as an Interaction.
 
## Parameters
- `incudeInteraction`: The Interaction to include for tracking.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.include(automaticInteraction: MXOAutomaticInteractionInclusion { builder in
     builder.viewController = self
 })
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 __weak typeof(self) weakSelf = self;
 [MedalliaMXO includeAutomaticInteraction:[MXOAutomaticInteractionInclusion initWithBuilder:^(MXOAutomaticInteractionInclusionBuilder * _Nonnull builder) {
     builder.viewController = weakSelf;
 }] error:&error];
 ```
 }
}
*/
+ (BOOL)includeAutomaticInteraction:(MXOAutomaticInteractionInclusion *)includeInteration
                     error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(include(automaticInteraction:));

/*!
Use to generate a `URL` for outbound link tracking.
 
## Parameters
- `link`: The `URL` for outbound link tracking.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.sendInteraction(forOutboundLink: URL(string: "yourUrl")!)
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 [MedalliaMXO sendInteractionForOutboundLink:[NSURL URLWithString:@"yourUrl"] error:nil];
 ```
 }
}
*/
+ (BOOL)sendInteractionForOutboundLink:(NSURL *)link
                                 error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(sendInteraction(forOutboundLink:));

/*!
Use to send a response code to MXO.
 
## Parameters
- `request`: The response code to be sent.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let interaction = MXOInteraction(withString: "/InteractionPath")
 let responseCode = MXOResponseCode(withResponseCode: "responseCode")
 MedalliaMXO.sendInteraction(responseCodeRequest: MXOResponseCodeRequest { builder in
     builder.interaction = interaction
     builder.responseCode = responseCode
     builder.onError = { error in
         // print error
     }
     builder.onSuccess = { response in
         // process response
     }
 })
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 MXOResponseCode *responseCode = [MXOResponseCode initWithResponseCode:@"responseCode" error:&error];
 MXOInteraction *interaction = [MXOInteraction initWithString:@"/InteractionPath" error:&error];
 [MedalliaMXO sendInteractionResponseCode:[MXOResponseCodeRequest initWithBuilder:^(MXOResponseCodeRequestBuilder * _Nonnull builder) {
     builder.interaction = interaction;
     builder.responseCode = responseCode;
     builder.onError = ^(NSError *error) {
         // print error
     };
     builder.onSuccess = ^(MXOInteractionResponse *response) {
         // process response
     };
 }] error:&error];
 ```
 }
}
*/
+ (BOOL)sendInteractionResponseCode:(MXOResponseCodeRequest *)request
                              error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(sendInteraction(responseCodeRequest:));

/*!
Use to send an Interaction to MXO.
 
## Parameters
- `request`: The Interaction request to be sent.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let interaction = MXOInteraction(withString: "/InteractionPath")
 MedalliaMXO.sendInteraction(request: MXOInteractionRequest { builder in
     builder.interaction = interaction
 })
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 MXOInteraction *interaction = [MXOInteraction initWithString:@"/InteractionPath" error:&error];
 [MedalliaMXO sendInteraction:[MXOInteractionRequest initWithBuilder:^(MXOInteractionRequestBuilder * _Nonnull builder) {
     builder.interaction = interaction;
 }] error:&error];
 ```
 }
}
*/
+ (BOOL)sendInteraction:(MXOInteractionRequest *)request
                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(sendInteraction(request:));

/*!
Use to send Properties to MXO.
 
## Parameters
- `request`: The Interaction request to be sent.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let interaction = MXOInteraction(withString: "/InteractionPath")
 let properties = ["key1":"value1","key2":"value2"]
 MedalliaMXO.sendProperties(request: MXOInteractionRequest { builder in
     builder.interaction = interaction
     builder.properties = properties
 })
  ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 NSDictionary *properties = @{@"Key1":@"Value1", @"Key2":@"Value2"};
 MXOInteraction *interaction = [MXOInteraction initWithString:@"/InteractionPath" error:&error];
 [MedalliaMXO sendProperties:[MXOInteractionRequest initWithBuilder:^(MXOInteractionRequestBuilder * _Nonnull builder) {
     builder.interaction = interaction;
     builder.properties = properties;
 }] error:&error];
 ```
 }
}
*/
+ (BOOL)sendProperties:(MXOInteractionRequest *)request
                 error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(sendProperties(request:));

/*!
Use to process the response returned from sending an Interaction to MXO.
 
All Tracking and Capture Points will be parsed by the framework as usual. All Optimization Points, known by the framework, will be processed/displayed.
 
## Parameters
- `response`: The Interaction response to process.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.process(response: response)
   ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 [MedalliaMXO processResponse:response error:&error];
 ```
 }
}
*/
+ (BOOL)processResponse:(MXOInteractionResponse *)response
                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(process(response:));

/*!
Use to process a `URL` deep link.

## Parameters
- `url`: The `URL` to process.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
  MedalliaMXO.process(deepLink: deepLink)
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 [MedalliaMXO processDeepLink:[NSURL URLWithString:@"yourUrl"] error:nil];
 ```
 }
}
*/
+ (BOOL)processDeepLink:(NSURL *)url
                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(process(deepLink:));

//=========================================
#pragma mark - Logging
//=========================================

/*!
The logging configuration of the MXO SDK.

Use to set or get the MXO SDK logging configuration. Set a specific logging configuration using ``MXOLogLevel`` and ``MXOLogComponent`` to see the framework outputs in the console panel.
*/
@property (class, nonatomic, nullable) MXOLoggingConfiguration *loggingConfiguration;

//=========================================
#pragma mark - Opt
//=========================================

/*!
The optout logging configuration of the MXO SDK.

Use to set or get the MXO SDK optout configuration. Set a specific optout configuration using ``MXOOptInOptions`` to opt a uset into a specific tracking.
*/
@property (class, nonatomic, nullable) MXOOptOutConfiguration *optOutConfiguration;

@end

NS_ASSUME_NONNULL_END
