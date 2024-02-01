//
//  MXOConfiguration.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOConfigurationBuilder;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - typedef
///////////////////////////////////////////////////////////////////////////////////////////
typedef void (^MXOConfigurationBuilderBlock)(MXOConfigurationBuilder *builder);


///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOConfiguration
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Required arguments for configuring the MXO SDK.
 */
@interface MXOConfiguration : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief The MXO space site key.
 */
@property (nonatomic, copy, readonly, nullable) NSString *siteKey;

/*!
   @brief The MXO touchpoint URI.
 */
@property (nonatomic, strong, readonly, nullable) NSURL *touchpoint;

/*!
   @brief The MXO server instance your space is hosted on.
 */
@property (nonatomic, strong, readonly, nullable) NSURL *host;

/*!
   @brief Define whether the framework is initialized in Admin or User mode. Set YES to initialize in Admin mode. Otherwise set NO to initialize in User mode.
 */
@property (nonatomic, assign, readonly) BOOL adminMode;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create a builder using "this" state.
 */
- (MXOConfigurationBuilder *)builder NS_SWIFT_NAME(builder());

- (instancetype)init NS_UNAVAILABLE;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Class Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create an instance using a builder.
 */
+ (instancetype)initWithBuilder:(nullable MXOConfigurationBuilderBlock)configBuilderBlock NS_SWIFT_NAME(init(withBuilder:));

@end

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOConfigurationBuilder
///////////////////////////////////////////////////////////////////////////////////////////
///
@interface MXOConfigurationBuilder : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief The MXO space site key.
 */
@property (nonatomic, copy, nullable) NSString *siteKey;

/*!
   @brief The MXO touchpoint URI.
 */
@property (nonatomic, strong, nullable) NSURL *touchpoint;

/*!
   @brief The MXO server instance your space is hosted on.
 */
@property (nonatomic, strong, nullable) NSURL *host;

/*!
   @brief Define whether the framework is initialized in Admin or User mode. Set YES to initialize in Admin mode. Otherwise set NO to initialize in User mode.
 */
@property (nonatomic, assign) BOOL adminMode;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////
/*!
   @brief Create an MXOConfiguration.
 */
- (MXOConfiguration *)build;

@end

NS_ASSUME_NONNULL_END
