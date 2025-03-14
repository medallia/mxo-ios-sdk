//
//  MedalliaConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2024 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MedalliaConfigurationBuilder;

//=========================================
#pragma mark - typedef
//=========================================

/*!
A block type used for building an ``MedalliaConfiguration`` object.
*/
typedef void (^MedalliaConfigurationBuilderBlock)(MedalliaConfigurationBuilder *builder);

//=========================================
#pragma mark - MedalliaConfiguration
//=========================================

/*!
The configuration object for the Medallia SDK.
 
 By default, Medallia SDK communication is enabled in the MXO SDK. However, you can limit this behavior.
 
 ## Properties
 - `disableInterSDKCommunication`: The boolean indicating whether the Medallia SDK communication is disabled.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.medalliaConfiguration = MedalliaConfiguration { builder in
    builder.disableInterSDKCommunication = true
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 MedalliaMXO.medalliaConfiguration = [MedalliaConfiguration initWithBuilder:^(MedalliaConfigurationBuilder * _Nonnull builder) {
    builder.disableInterSDKCommunication = true
 }];
 ```
 }
}
*/
@interface MedalliaConfiguration : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The boolean indicating whether the Medallia SDK communication is disabled.
 
Set to `true` to disable Medallia SDK communication.
*/
@property (nonatomic, assign, readonly) BOOL disableInterSDKCommunication;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for a ``MedalliaConfiguration``.
 
## Returns
An instance of ``MedalliaConfigurationBuilder``.
*/
- (MedalliaConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MedalliaConfiguration`` using the provided `builder` block.
 
## Parameters
- `configBuilderBlock`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(nullable MedalliaConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MedalliaConfigurationBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MedalliaConfiguration`` objects.
 
 ## Properties
 - `disableInterSDKCommunication`: The boolean indicating whether the Medallia SDK communication is disabled.
*/
@interface MedalliaConfigurationBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The boolean indicating whether the Medallia SDK communications is disabled.
 
Set to `true` to disable Medallia SDK communication.
*/
@property (nonatomic, assign) BOOL disableInterSDKCommunication;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a ``MedalliaConfiguration`` object.
 
## Returns
An instance of ``MedalliaConfiguration``.
*/
- (MedalliaConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
