//
//  MXOIdentityTransferUriMatcher.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
   @brief A way of matching different URLs for identity transfer.
 */
@interface MXOIdentityTransferUriMatcher : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

@property (atomic, strong, readonly) id _Nullable value;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

- (instancetype)init NS_UNAVAILABLE;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Class Methods
///////////////////////////////////////////////////////////////////////////////////////////

/*!
   @brief Create a matcher using an exact URL.
 */
+ (nullable instancetype)initWithUrl:(nullable NSURL *)url
                               error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withUrl:));

/*!
   @brief Create a matcher using a regex for more flexibility.
 */
+ (nullable instancetype)initWithRegex:(nullable NSRegularExpression *)regex
                                 error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withRegex:));

@end

NS_ASSUME_NONNULL_END
