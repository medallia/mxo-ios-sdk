//
//  MedalliaMXOConfiguration.h
//  Medallia
//
//  Copyright © 2022 Medallia. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MedalliaMXOConfiguration : NSObject

- (instancetype)init NS_UNAVAILABLE;

/*!
@brief Returns a singleton class.
 */
+ (instancetype)shared;

/*!
@brief Returns the current configuration.
 */
+ (MedalliaMXOConfiguration *)currentConfiguration NS_SWIFT_NAME(currentConfiguration());

/**
 *  The ONE Engagement Hub space site key.
 */
@property (nonatomic, copy) NSString *siteKey;

/**
 *  The ONE Engagement Hub space Touchpoint URI.
 */
@property (nonatomic, copy) NSString *touchpointURI;

/**
 *  The ONE Engagement Hub space API key.
 */
@property (nonatomic, copy) NSString *apiKey;

/**
 *  The ONE Engagement Hub space shared secret key.
 */
@property (nonatomic, copy) NSString *sharedSecret;

/**
 *  The ONE Engagement Hub space userId.
 */
@property (nonatomic, copy) NSString *userId;

/**
 *  Returns whether the framework is initialized in Admin or User mode. Returns YES if in Admin mode. Otherwise returns NO if in User mode.
 */
@property (nonatomic, getter=isAdminMode) BOOL adminMode;

/**
 *  The ONE Engagement Hub space host name.
 */
@property (nonatomic, copy) NSString *hostName;

@end
