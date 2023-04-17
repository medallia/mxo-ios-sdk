//
//  MXOOptOutConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOOptOutConfigurationBuilder;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - typedef
///////////////////////////////////////////////////////////////////////////////////////////
typedef void (^MXOOptOutConfigurationBuilderBlock)(MXOOptOutConfigurationBuilder *builder);


///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOOptOutConfiguration
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Required arguments for configuring the MXO SDK.
 */
@interface MXOOptOutConfiguration : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

@property (nonatomic, assign, readonly) BOOL optOut;

@property (nonatomic, assign, readonly) MXOOptInOptions optInOptions;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create a builder using "this" state.
 */
- (MXOOptOutConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Class Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create an instance using a builder.
 */
+ (instancetype)initWithBuilder:(nullable MXOOptOutConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOOptOutConfigurationBuilder
///////////////////////////////////////////////////////////////////////////////////////////
///
@interface MXOOptOutConfigurationBuilder : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

@property (nonatomic, assign) BOOL optOut;

@property (nonatomic, assign) MXOOptInOptions optInOptions;


///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////
/*!
   @brief Create an MXOOptOutConfiguration.
 */
- (MXOOptOutConfiguration *)build;

@end

NS_ASSUME_NONNULL_END