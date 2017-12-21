//
//  ProvisioningSDKDelegate.h
//  ProvisioningSDK
//
//  Created by Alejandro Espinosa on 3/5/17.
//  Copyright © 2017 Fon. All rights reserved.
//

@import Foundation;
#import "FPRCredentials.h"

/**
 Delegate of the ProvisioningSDK class.
 */
@protocol ProvisioningSDKDelegate <NSObject>

/**
 Credentials with the data to generate the networks that it can connect.
 
 @return Credentials with the data to generate the networks that it can connect.
 */
- (FPRCredentials *)credentials;

@end
