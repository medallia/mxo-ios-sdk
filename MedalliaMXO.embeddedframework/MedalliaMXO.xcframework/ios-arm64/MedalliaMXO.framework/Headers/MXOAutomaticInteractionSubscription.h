//
//  MXOAutomaticInteractionSubscription.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

@class MXOInteraction;

@protocol MXOAutomaticInteractionSubscription <NSObject>

@property (nonatomic, strong, readonly) MXOInteraction *interaction;

- (void)unsubscribe;

@end
