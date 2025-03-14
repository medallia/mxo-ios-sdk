//
//  MXOResponseCode.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//=========================================
#pragma mark - MXOResponseCode
//=========================================

/*!
The response code object containing the response code value.
 
Used as part of the ``MXOResponseCodeRequest`` object. Response code values is sent to the MXO API as a property value.
 
## Properties
- `value`: The response code `String` value.
*/
@interface MXOResponseCode : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The response code `String` value.
*/
@property (nonatomic, copy, nullable) NSString *value;

//=========================================
#pragma mark - Instance Methods
//=========================================

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Use to send an Interaction response code.
 
Can useful when displaying Optimizations programmatically and capturing the user's response.
 
## Parameters
- `code`: The response code to be sent.
- `error`: Used to handle errors.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MXOResponseCode(withResponseCode: "responseCode")
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 [MXOResponseCode initWithResponseCode:@"responseCode" error:&error];
 ```
 }
}
*/
+ (nullable instancetype)initWithResponseCode:(NSString *)code
                                        error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withResponseCode:));

@end

NS_ASSUME_NONNULL_END
