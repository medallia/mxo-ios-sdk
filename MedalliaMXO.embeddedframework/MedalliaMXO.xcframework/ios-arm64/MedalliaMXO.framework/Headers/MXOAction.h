//
//  MXOAction.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOAsset, MXOProposition;

@interface MXOAction : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *name;

@property (nonatomic, strong, nullable, readonly) MXOProposition *proposition;

@property (nonatomic, strong, nullable, readonly) MXOAsset *asset;

@end

NS_ASSUME_NONNULL_END
