//
//  MXOProposition.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//=========================================
#pragma mark - typedef
//=========================================

/*!
The enum which specifies the type of a Proposition.
 
## Options
- `MXOPropositionTypeProduct`: The product Proposition.
- `MXOPropositionTypeService`: The service Proposition.
*/
typedef NS_ENUM(NSInteger, MXOPropositionType) {
    /**
    * The product Proposition.
    */
    MXOPropositionTypeProduct NS_SWIFT_NAME(product),
    /**
    * The service Proposition.
    */
    MXOPropositionTypeService NS_SWIFT_NAME(service)
};

//=========================================
#pragma mark - MXOProposition
//=========================================

/*!
The MXO Proposition.
 
Propositions are the products or services that you want to promote to customers.
 
## Properties
- `name`: The Proposition name.
- `code`: The business code associated with a Proposition.
- `type`: The type of a Proposition.
*/
@interface MXOProposition : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The Proposition name.
*/
@property (nonatomic, copy, nullable, readonly) NSString *name;

/*!
The business code associated with a Proposition.
*/
@property (nonatomic, copy, nullable, readonly) NSString *code;

/*!
The type of a Proposition.
*/
@property (nonatomic, assign, readonly) MXOPropositionType type;

@end

NS_ASSUME_NONNULL_END
