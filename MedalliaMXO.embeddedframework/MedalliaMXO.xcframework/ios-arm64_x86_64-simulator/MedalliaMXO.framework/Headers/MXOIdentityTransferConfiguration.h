//
//  MXOIdentityTransferConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOIdentityTransferConfigurationBuilder, MXOIdentityTransferUriMatcher;

//=========================================
#pragma mark - typedef
//=========================================

/*!
A block type used for building an``MXOIdentityTransferConfiguration`` object.
*/
typedef void (^MXOIdentityTransferConfigurationBuilderBlock)(MXOIdentityTransferConfigurationBuilder *builder);

//=========================================
#pragma mark - MXOIdentityTransferConfiguration
//=========================================

/*!
The configuration object for MXO SDK identity transfer.
 
The MXO SDK appends a tid `URL` query parameter to all links opened from a mobile app by default. However, you can limit this behavior.
 
## Properties
- `disableIdentityTransfer`: The boolean indicating whether the identity transfer is disabled.
- `includeList`: The list of allowed URIs for identity transfer.
- `excludeList`: The list of denied URIs for identity transfer.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.identityTransferConfiguration = MXOIdentityTransferConfiguration { builder in
     builder.disableIdentityTransfer = true
     builder.includeList = includeList
     builder.excludeList = excludeList
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 MedalliaMXO.identityTransferConfiguration = [MXOIdentityTransferConfiguration initWithBuilder:^(MXOIdentityTransferConfigurationBuilder * _Nonnull builder) {
     builder.disableIdentityTransfer = YES;
     builder.includeList = [includeList];
     builder.excludeList = [excludeList];
 }];
 ```
 }
}
*/
@interface MXOIdentityTransferConfiguration : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
 A boolean indicating whether identity transfer is disabled.

 When `disableIdentityTransfer` is set to `true`, the MXO SDK prevents appending a TID query parameter to outbound links.

 Set this property to `true` to disable the transfer of identity to outbound locations.
*/
@property (nonatomic, readonly) BOOL disableIdentityTransfer;

/*!
The list of allowed `URI`s for identity transfer.
 
Prevents the MXO SDK from appending a TID query parameter to outbound links that are not in this list.
*/
@property (atomic, strong, readonly, nullable) NSArray<MXOIdentityTransferUriMatcher *> *includeList;

/*!
The list of denied `URI`s for identity transfer.
 
Prevents the MXO SDK from appending a TID query parameter to outbound links that are in this list.
*/
@property (atomic, strong, readonly, nullable) NSArray<MXOIdentityTransferUriMatcher *> *excludeList;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOIdentityTransferConfiguration``.
 
## Returns
An instance of ``MXOIdentityTransferConfigurationBuilder``.
*/
- (MXOIdentityTransferConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOIdentityTransferConfiguration`` using the provided `builder` block.
 
## Parameters
- `configBuilderBlock`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(nullable MXOIdentityTransferConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));
@end

//=========================================
#pragma mark - MXOIdentityTransferConfigurationBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOIdentityTransferConfiguration`` objects.
 
Provides a convenient way to configure the identity transfer for the SDK.
 
 ## Properties
- `disableIdentityTransfer`: The boolean indicating whether the identity transfer is disabled.
- `includeList`: The list of allowed URIs for identity transfer.
- `excludeList`: The list of denied URIs for identity transfer.
*/
@interface MXOIdentityTransferConfigurationBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The boolean indicating whether the identity transfer is disabled.
 
Prevents the MXO SDK from appending a TID query parameter to outbound links.
 
Set to `true` to disable transfer of identity to outbound locations.
*/
@property (nonatomic, assign) BOOL disableIdentityTransfer;

/*!
The list of allowed `URI`s for identity transfer.
 
Prevents the MXO SDK from appending a TID query parameter to outbound links that are not in this list.
*/
@property (atomic, strong, nullable) NSArray<MXOIdentityTransferUriMatcher *> *includeList;

/*!
The list of denied `URI`s for identity transfer.
 
Prevents the MXO SDK from appending a TID query parameter to outbound links that are in this list.
*/
@property (atomic, strong, nullable) NSArray<MXOIdentityTransferUriMatcher *> *excludeList;

//=========================================
#pragma mark - Instance Methdods
//=========================================

/*!
Creates an ``MXOIdentityTransferConfiguration`` object.
 
## Returns
An instance of ``MXOIdentityTransferConfiguration``.
*/
- (MXOIdentityTransferConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
