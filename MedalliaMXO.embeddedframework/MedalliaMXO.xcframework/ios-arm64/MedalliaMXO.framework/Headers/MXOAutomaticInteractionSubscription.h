//
//  MXOAutomaticInteractionSubscription.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

@class MXOInteraction;

//=========================================
#pragma mark - MXOAutomaticInteractionSubscription
//=========================================

/*!
The subscription protocol for an automatic MXO Interaction.
 
## Properties
 - `interaction`: The MXO Interaction object to subscribe to.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 var subscription: MXOAutomaticInteractionSubscription?
 let interaction = MXOInteraction(withString: "/InteractionPath")
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
@protocol MXOAutomaticInteractionSubscription <NSObject>

//=========================================
#pragma mark - Properties
//=========================================

/*!
The MXO Interaction to subscribe.
*/
@property (nonatomic, strong, readonly) MXOInteraction *interaction;

/*!
Used to unsubscribe from the automatic Interaction tracking.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 if let subscription = subscription {
     subscription.unsubscribe()
 }
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 [subscription unsubscribe];
 ```
 }
}
*/
- (void)unsubscribe;

@end
