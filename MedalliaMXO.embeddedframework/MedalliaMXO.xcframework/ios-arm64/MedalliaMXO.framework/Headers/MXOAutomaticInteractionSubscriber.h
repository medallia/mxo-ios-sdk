//
//  MXOAutomaticInteractionSubscriber.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOInteractionResponse, MXOInteraction, MXOAutomaticInteractionSubscriberBuilder;

//=========================================
#pragma mark - Typedef
//=========================================

/*!
Provides an MXO Interaction response handler.
*/
typedef void (^MXOAutomaticInteractionOnResponseBlock)(MXOInteractionResponse *response);

/*!
A block type used for building an ``MXOAutomaticInteractionSubscriber`` object.
*/
typedef void (^MXOAutomaticInteractionSubscriberBuilderBlock)(MXOAutomaticInteractionSubscriberBuilder *builder);

//=========================================
#pragma mark - MXOAutomaticInteractionSubscriber
//=========================================

/*!
The subscriber for receiving automatic Interaction responses.
 
## Properties
- `interaction`: The MXO Interaction to subscribe.
- `onResponse`: The MXO Interaction response handler.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 var subscription: MXOAutomaticInteractionSubscription?
 if let interaction = try? MXOInteraction(withViewController: self) {
     subscription = try? MedalliaMXO.subscribe(toAutomaticInteraction: MXOAutomaticInteractionSubscriber { builder in
         builder.interaction = interaction
         builder.onResponse = {
             // do something with a response
         }
     })
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 MXOInteraction *interaction = [MXOInteraction initWithString:@"/InteractionPath" error:&error];
 id subscription = [MedalliaMXO subscribeToAutomaticInteraction:[MXOAutomaticInteractionSubscriber initWithBuilder:^(MXOAutomaticInteractionSubscriberBuilder * _Nonnull builder) {
     builder.interaction = interaction;
     builder.onResponse = ^(MXOInteractionResponse *response) {
         // do something with a response
     };
 }] error:&error];
 ```
 }
}
*/
@interface MXOAutomaticInteractionSubscriber : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The MXO Interaction to subscribe.
*/
@property (nonatomic, strong, readonly) MXOInteraction *interaction;

/*!
 The MXO Interaction response handler.
*/
@property (nonatomic, copy, readonly, nullable) MXOAutomaticInteractionOnResponseBlock onResponse;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Create a builer for an ``MXOAutomaticInteractionSubscriber``.
*/
- (MXOAutomaticInteractionSubscriberBuilder *)builder;

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOAutomaticInteractionSubscriber`` using the provided `builder` block.
 
## Parameters
- `block`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(MXOAutomaticInteractionSubscriberBuilderBlock)block NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOAutomaticInteractionSubscriberBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOAutomaticInteractionSubscriber`` objects.
 
## Properties
- `interaction`: The MXO Interaction to subscribe.
- `onResponse`: The MXO Interaction response handler.
*/
@interface MXOAutomaticInteractionSubscriberBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================
/*!
The MXO Interaction to subscribe.
*/
@property (nonatomic, strong) MXOInteraction *interaction;

/*!
The MXO Interaction response handler.
*/
@property (nonatomic, copy, nullable) MXOAutomaticInteractionOnResponseBlock onResponse;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOAutomaticInteractionSubscriber`` object.
 
## Returns
An instance of ``MXOAutomaticInteractionSubscriber``.
*/
- (MXOAutomaticInteractionSubscriber *)build;

@end

NS_ASSUME_NONNULL_END
