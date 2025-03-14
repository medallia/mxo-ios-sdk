//
//  MXOAction.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOAsset, MXOProposition;

//=========================================
#pragma mark - MXOAction
//=========================================

/*!
The MXO Action object holding Optimizations for a Touchpoint.
 
## Properties
- `name`: The name of an Action.
- `proposition`: An optional Proposition for an Action.
- `asset`: The Asset for an Action.
*/
@interface MXOAction : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The name of an Action.
*/
@property (nonatomic, copy, nullable, readonly) NSString *name;

/*!
An optional Proposition for an Action.
*/
@property (nonatomic, strong, nullable, readonly) MXOProposition *proposition;

/*!
The Asset for an Action.
*/
@property (nonatomic, strong, nullable, readonly) MXOAsset *asset;

@end

NS_ASSUME_NONNULL_END
