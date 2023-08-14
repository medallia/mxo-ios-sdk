//
//  MXOOptimizationPoint.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MXOOptimizationPointDirectives) {
    MXOOptimizationPointDirectiveReplace NS_SWIFT_NAME(replace),
    MXOOptimizationPointDirectiveBefore NS_SWIFT_NAME(before),
    MXOOptimizationPointDirectiveAfter NS_SWIFT_NAME(after),
    MXOOptimizationPointDirectiveUnknown NS_SWIFT_NAME(unknown)
};

@class MXOAction;

@interface MXOOptimizationPoint : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *path;

@property (nonatomic, assign, readonly) MXOOptimizationPointDirectives directives;

@property (nonatomic, strong, nullable, readonly) NSArray<MXOAction *> *actions;

@end
