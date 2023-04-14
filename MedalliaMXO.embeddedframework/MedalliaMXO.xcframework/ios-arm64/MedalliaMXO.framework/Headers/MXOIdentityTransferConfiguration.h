//
//  MXOIdentityTransferConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOIdentityTransferConfigurationBuilder, MXOIdentityTransferUriMatcher;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - typedef
///////////////////////////////////////////////////////////////////////////////////////////

typedef void (^MXOIdentityTransferConfigurationBuilderBlock)(MXOIdentityTransferConfigurationBuilder *builder);

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOIdentityTransferConfiguration
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Configuration Object for Identity Transfer.
 */
@interface MXOIdentityTransferConfiguration : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Prevent the MXO SDK from appending a TID query parameter to outbound links.
 */
@property (nonatomic, readonly) BOOL disableIdentityTransfer;

/*!
   @brief Prevent the MXO SDK from appending a TID query parameter to outbound links that are not in this included list.
 */
@property (atomic, strong, readonly, nullable) NSArray<MXOIdentityTransferUriMatcher *> *includeList;

/*!
   @brief Prevent the MXO SDK from appending a TID query parameter to outbound links that are excluded in this exclude list.
 */
@property (atomic, strong, readonly, nullable) NSArray<MXOIdentityTransferUriMatcher *> *excludeList;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create a builder from "this"  state.
 */
- (MXOIdentityTransferConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Class Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create a using a builder.
 */
+ (instancetype)initWithBuilder:(nullable MXOIdentityTransferConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));
@end

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOIdentityTransferConfigurationBuilder
///////////////////////////////////////////////////////////////////////////////////////////

@interface MXOIdentityTransferConfigurationBuilder : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Prevent the MXO SDK from appending a TID query parameter to outbound links.
 */
@property (nonatomic, assign) BOOL disableIdentityTransfer;

/*!
   @brief Prevent the MXO SDK from appending a TID query parameter to outbound links that are not in this included list.
 */
@property (atomic, strong, nullable) NSArray<MXOIdentityTransferUriMatcher *> *includeList;

/*!
   @brief Prevent the MXO SDK from appending a TID query parameter to outbound links that are excluded in this exclude list.
 */
@property (atomic, strong, nullable) NSArray<MXOIdentityTransferUriMatcher *> *excludeList;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methdods
///////////////////////////////////////////////////////////////////////////////////////////

- (MXOIdentityTransferConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
