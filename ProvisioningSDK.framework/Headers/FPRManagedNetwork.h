//
//  FPRManagedNetwork.h
//  ProvisioningSDK
//
//  Created by Alejandro Espinosa on 3/5/17.
//  Copyright © 2017 Fon. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The type of managed network.
 */
typedef NS_ENUM(NSUInteger, FPRManagedNetworkType){
    /**
     The network is not managed.
     */
    FPRManagedNetworkTypeNone = 0,
    /**
     The network is captive.
     */
    FPRManagedNetworkTypeCaptive,
    /**
     The network is EAP.
     */
    FPRManagedNetworkTypeEAP
};

@interface FPRManagedNetwork : NSObject<NSCoding>

/** FPRManagedNetworkType with the type of network. */
@property (assign, nonatomic) FPRManagedNetworkType managedNetworkType;

/** NSString with the SSID. */
@property (copy, nonatomic) NSString *SSID;

/** NSString with the information needed to check if the network is secure. */
@property (copy, nonatomic) NSString *fqdn;

/** NSString with the VNP. */
@property (copy, nonatomic) NSString *vnp;

@end
