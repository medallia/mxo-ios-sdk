//
//  MXOInteraction.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
   @brief An MXO Interaction. Conceptually a URI.
 */
@interface MXOInteraction : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

@property (atomic, strong, readonly, nullable) NSURL *value;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

- (instancetype)init NS_UNAVAILABLE;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Class Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create an interaction from a URL.
 */
+ (nullable instancetype)initWithUrl:(NSURL *)url
                               error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withUrl:));

/*!
   @brief Create an interaction from a string.
 */
+ (nullable instancetype)initWithString:(NSString *)urlString
                                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withString:));
/*!
   @brief Create an interaction from a ViewController.
 */
+ (nullable instancetype)initWithViewController:(UIViewController *)viewController
                                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withViewController:));

@end

NS_ASSUME_NONNULL_END
