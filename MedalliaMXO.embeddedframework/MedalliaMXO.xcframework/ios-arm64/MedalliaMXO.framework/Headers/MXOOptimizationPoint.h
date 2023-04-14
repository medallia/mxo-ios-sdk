//
//  MXOOptimizationPoint.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

@class MXOAction;

@interface MXOOptimizationPoint : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *path;

@property (nonatomic, strong, nullable, readonly) NSArray<MXOAction *> *actions;

@end
