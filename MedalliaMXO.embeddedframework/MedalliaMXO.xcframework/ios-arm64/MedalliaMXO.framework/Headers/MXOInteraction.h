//
//  MXOInteraction.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//=========================================
#pragma mark - MXOInteraction
//=========================================
/*!
The MXO Interaction object.
 
Interactions are the key elements of the customer experience, representing the ongoing conversation between your customer and your organization at any of your Touchpoints.
 
## Properties
- `value`: The `URL` representation of the Interaction.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let interaction = MXOInteraction(withString: "/InteractionPath")
 MedalliaMXO.sendInteraction(request: MXOInteractionRequest { builder in
     builder.interaction = interaction
 })
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 MXOInteraction *interaction = [MXOInteraction initWithString:@"/InteractionPath" error:&error];
 [MedalliaMXO sendInteraction:[MXOInteractionRequest initWithBuilder:^(MXOInteractionRequestBuilder * _Nonnull builder) {
     builder.interaction = interaction;
 }] error:&error];
 ```
 }
}
*/
@interface MXOInteraction : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The `URL` representation of the Interaction.
*/
@property (atomic, strong, readonly, nullable) NSURL *value;

//=========================================
#pragma mark - Instance Methods
//=========================================

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an Interaction from a `URL`.
 
## Parameters
- `url`: The `URL` to create an Interaction from.
- `error`: Used to handle errors.
*/
+ (nullable instancetype)initWithUrl:(NSURL *)url
                               error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withUrl:));

/*!
Creates an Interaction from a `String`.
 
## Parameters
- `urlString`: The `String` to create an Interaction from.
- `error`: Used to handle errors.
*/
+ (nullable instancetype)initWithString:(NSString *)urlString
                                  error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withString:));
/*!
Creates an Interaction from a `UIViewController`.
 
## Parameters
- `viewController`: The `UIViewController` to create an Interaction from.
- `error`: Used to handle errors.
*/
+ (nullable instancetype)initWithViewController:(UIViewController *)viewController
                                          error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withViewController:));

@end

NS_ASSUME_NONNULL_END
