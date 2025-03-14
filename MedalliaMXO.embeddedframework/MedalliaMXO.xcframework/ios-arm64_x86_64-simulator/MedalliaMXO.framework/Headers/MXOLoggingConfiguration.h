//
//  MXOLoggingConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOLoggingConfigurationBuilder;

//=========================================
#pragma mark - typedef
//=========================================

/*!
A block type used for building an ``MXOLoggingConfiguration`` object.
*/
typedef void (^MXOLoggingConfigurationBuilderBlock)(MXOLoggingConfigurationBuilder *builder);

//=========================================
#pragma mark - MXOLoggingConfiguration
//=========================================

/*!
The logging configuration object for the MXO SDK.
 
Used to debug or reporting purposes. The API can be configured to log any combination of ``MXOLogComponent``s (features or technical concepts such as Interaction or Networking) to ``MXOLogLevel``s (Verbose, Debug, etc.).
 
## Properties
 - `logLevel`: The list of levels to filter the messages the MXO SDK will print to console.
- `logComponent`: The list of components to filter the messages the MXO SDK will print to console.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.loggingConfiguration = MXOLoggingConfiguration { builder in
     builder.logLevel = .verbose
     builder.logComponent = .any
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 MedalliaMXO.loggingConfiguration = [MXOLoggingConfiguration initWithBuilder:^(MXOLoggingConfigurationBuilder * _Nonnull builder) {
     builder.logLevel = MXOLogLevelVerbose;
     builder.logComponent = MXOLogComponentAny;
 }];
 ```
 }
}
*/
@interface MXOLoggingConfiguration : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The list of levels to filter the messages the MXO SDK will print to console.
*/
@property (nonatomic, assign, readonly) MXOLogLevel logLevel;

/*!
The list of components to filter the messages the MXO SDK will print to console.
*/
@property (nonatomic, assign, readonly) MXOLogComponent logComponent;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOLoggingConfiguration``.
 
## Returns
An instance of ``MXOLoggingConfigurationBuilder``.
*/
- (MXOLoggingConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOLoggingConfiguration`` using the provided `builder` block.
 
## Parameters
- `configBuilderBlock`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(nullable MXOLoggingConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOLoggingConfigurationBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOLoggingConfiguration`` objects.

Provides a convenient way to configure the logging settings for the SDK.
 
## Properties
- `logLevel`: The list of levels to filter the messages the MXO SDK will print to console.
- `logComponent`: The list of components to filter the messages the MXO SDK will print to console.
*/
@interface MXOLoggingConfigurationBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/**
The list of levels to filter the messages the MXO SDK will print to console.
 */
@property (nonatomic, assign) MXOLogLevel logLevel;

/**
The list of components to filter the messages the MXO SDK will print to console.
*/
@property (nonatomic, assign) MXOLogComponent logComponent;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOLoggingConfiguration`` object.
 
## Returns
An instance of ``MXOLoggingConfiguration``.
*/
- (MXOLoggingConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
