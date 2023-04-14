//
//  MXOProposition.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MXOPropositionType) {
    MXOPropositionTypeProduct NS_SWIFT_NAME(product),
    MXOPropositionTypeService NS_SWIFT_NAME(service)
};

@interface MXOProposition : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *name;

@property (nonatomic, copy, nullable, readonly) NSString *code;

@property (nonatomic, assign, readonly) MXOPropositionType type;

@end

NS_ASSUME_NONNULL_END
