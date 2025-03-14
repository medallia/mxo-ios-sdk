//
//  MXOOptimizationPoint.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

//=========================================
#pragma mark - typedef
//=========================================

/*!
The enum which specifies the position to place an Optimization to.
 
## Options
- `MXOOptimizationPointDirectiveReplace`: The Asset replaces the content area.
- `MXOOptimizationPointDirectiveBefore`: The Asset is inserted before the content area.
- `MXOOptimizationPointDirectiveAfter`: The Asset is inserted after the content area.
- `MXOOptimizationPointDirectiveUnknown`: The unknown directives for an Asset.
*/
typedef NS_ENUM(NSInteger, MXOOptimizationPointDirectives) {
    /**
    * The Asset replaces the content area.
    */
    MXOOptimizationPointDirectiveReplace NS_SWIFT_NAME(replace),
    /**
    * The Asset is inserted before the content area.
    */
    MXOOptimizationPointDirectiveBefore NS_SWIFT_NAME(before),
    /**
    * The Asset is inserted after the content area.
    */
    MXOOptimizationPointDirectiveAfter NS_SWIFT_NAME(after),
    /**
    * The unknown directives for an Asset.
    */
    MXOOptimizationPointDirectiveUnknown NS_SWIFT_NAME(unknown)
};

@class MXOAction;

//=========================================
#pragma mark - MXOOptimizationPoint
//=========================================

/*!
The optimized content of a Touchpoint which a user interacts with.
 
## Properties
- `path`: The location to Optimize.
- `directives`: The position of an Optimization.
- `actions`: The set of MXO Actions available to take for an Optimization.
*/
@interface MXOOptimizationPoint : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The location to Optimize.
*/
@property (nonatomic, copy, nullable, readonly) NSString *path;

/*!
The position of an Optimization.
*/
@property (nonatomic, assign, readonly) MXOOptimizationPointDirectives directives;

/*!
The set of MXO Actions available to take for an Optimization.
*/
@property (nonatomic, strong, nullable, readonly) NSArray<MXOAction *> *actions;

@end
