//
//  MXOIdentityTransferUriMatcher.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//=========================================
#pragma mark - MXOIdentityTransferUriMatcher
//=========================================
/*!
The `URI` matcher for identity transfer.

Represents the different ways the MXO SDK will attempt to include or exclude `URI`s from having a TID query parameter and value appended, IE identity transfer.
 
## Properies
 - `value`: The value of `URI` matcher.
*/
@interface MXOIdentityTransferUriMatcher : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The value of `URI` matcher.
*/
@property (atomic, strong, readonly) id _Nullable value;

//=========================================
#pragma mark - Instance Methods
//=========================================

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Create a matcher using an exact `URL`.
 
## Parameters
- `url`: The `URL` to match.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MXOIdentityTransferUriMatcher(withUrl: url) {
     // do something with a url
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 [MXOIdentityTransferUriMatcher initWithUrl:[NSURL URLWithString:@"www.url.com"] error:&error];
```
 }
}
*/
+ (nullable instancetype)initWithUrl:(nullable NSURL *)url
                               error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withUrl:));

/*!
Create a matcher using a regex for more flexibility.
 
## Parameters
- `regex`: The regex to match against the string representation of the `URL`.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MXOIdentityTransferUriMatcher(withRegex: NSRegularExpression(pattern: ".*\\.wikipedia\\.com")) {
     // do something with a url
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 [MXOIdentityTransferUriMatcher initWithRegex:[NSRegularExpression regularExpressionWithPattern:@".*\\.wikipedia\\.com" options:0 error:nil] error:&error];
 ```
 }
}
*/
+ (nullable instancetype)initWithRegex:(nullable NSRegularExpression *)regex
                                 error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withRegex:));

@end

NS_ASSUME_NONNULL_END
