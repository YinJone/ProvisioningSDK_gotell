//
//  ProvisioningErrors.h
//  ProvisioningSDK
//
//  Created by Alejandro Espinosa on 3/5/17.
//  Copyright © 2017 Fon. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ENUM(NSInteger) {
    /**
     OAuth error when the client id is nil.
     */
    FPREmptyClientIDError = 1001,
    /**
     OAuth error when the client secret is nil.
     */
    FPREmptyClientSecretError = 1002,
    /**
     Network error when the Home Service Provider is nil.
     */
    FPREmptyHSPError = 2001,
    /**
     Network error when the managed networks can not be stored.
     */
    FPRStoreManagedNetworksError = 2002,
    /**
     Network error when the JSON FPR provide HSP is invalid.
     */
    FPRWifiHSPInformationJSONError = 2003,
    /**
     Network error when the JSON FPR provide HSP is invalid.
     */
    FPRWifiVNPsInformationJSONError = 2004,
    /**
     MobileConfigURL error when EmptyWifiVNPsInformation is nil.
     */
    FPREmptyWifiVNPsInformationError = 3001,
    /**
     MobileConfigURL error when URLScheme is nil.
     */
    FPREmptyURLSchemeError = 3002
    };
    
    FOUNDATION_EXPORT NSString * const FPRNetworkingOperationFailingURLResponseErrorKey;

