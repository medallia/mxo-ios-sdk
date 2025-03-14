//
//  MXOConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOConfigurationBuilder;

//=========================================
#pragma mark - typedef
//=========================================

/*!
A block type used for building an ``MXOConfiguration`` object.
*/
typedef void (^MXOConfigurationBuilderBlock)(MXOConfigurationBuilder *builder);

//=========================================
#pragma mark - MXOConfiguration
//=========================================

/*!
The configuration object for the MXO SDK. 
 
Required arguments for configuring the SDK. The MXO SDK does not support partial, or piecemeal, configuration. You must provide all parameters, either all valid or invalid (empty string or nil). When configured with invalid parameters, the SDK is set in an unconfigured state.
 
## Properties
- `siteKey`: The MXO workspace to configure the SDK with.
- `touchpoint`: The MXO Touchpoint to configure the SDK with.
- `host`: The MXO host to send data to.
- `adminMode`: The Mode of the MXO SDK.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.configuration = MXOConfiguration { builder in
     builder.adminMode = true
     builder.touchpoint = URL(string: "myAppsNameURI")
     builder.host = URL(string: "eu2.thunderhead.com")
     builder.siteKey = "ONE-XXXXXXXXXX-1022"
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 MedalliaMXO.configuration = [MXOConfiguration initWithBuilder:^(MXOConfigurationBuilder * _Nonnull builder) {
     builder.adminMode = YES;
     builder.touchpoint = [NSURL URLWithString:@"myAppsNameURI"];
     builder.host = [NSURL URLWithString:@"eu2.thunderhead.com"];
     builder.siteKey = @"ONE-XXXXXXXXXX-1022";
 }];
 ```
 }
}
*/
@interface MXOConfiguration : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The MXO workspace to configure the SDK with.
*/
@property (nonatomic, copy, readonly, nullable) NSString *siteKey;

/*!
The MXO Touchpoint to configure the SDK with.
*/
@property (nonatomic, strong, readonly, nullable) NSURL *touchpoint;

/*!
The MXO host to send data to.
*/
@property (nonatomic, strong, readonly, nullable) NSURL *host;

/*!
The mode of the MXO SDK.
 
 If `adminMode` is `true`, the SDK is configured in Admin mode.

 If `adminMode` is `false`, the SDK is configured in User mode.
*/
@property (nonatomic, assign, readonly) BOOL adminMode;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOConfiguration``.
 
## Returns
An instance of ``MXOConfigurationBuilder``.
*/
- (MXOConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOConfiguration`` using the provided `builder` block.
 
## Parameters
- `configBuilderBlock`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(nullable MXOConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOConfigurationBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOConfiguration`` objects.
 
## Properties
- `siteKey`: The MXO workspace to configure the SDK with.
- `touchpoint`: The MXO Touchpoint to configure the SDK with.
- `host`: The MXO host to send data to.
- `adminMode`: The Mode of the MXO SDK.
*/
@interface MXOConfigurationBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The MXO workspace to configure the SDK with.
*/
@property (nonatomic, copy, nullable) NSString *siteKey;

/*!
The MXO Touchpoint to configure the SDK with.
*/
@property (nonatomic, strong, nullable) NSURL *touchpoint;

/*!
The MXO host to send data to.
*/
@property (nonatomic, strong, nullable) NSURL *host;

/*!
The mode of the MXO SDK.
 
If `adminMode` is set to `true`, the SDK will be configuted in Admin mode.
 
If `adminMode` is set to `false`, the SDK will be configuted in User mode.
*/
@property (nonatomic, assign) BOOL adminMode;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOConfiguration`` object.
 
## Returns
An instance of ``MXOConfiguration``.
*/
- (MXOConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
